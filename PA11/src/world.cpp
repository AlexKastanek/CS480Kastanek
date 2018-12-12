#include "world.h"
#include "graphics.h"

World::World() : Physics()
{

}

World::World(glm::vec3 gravity) : Physics(gravity)
{

}

World::~World()
{
    
}

bool World::Initialize()
{
  btDefaultCollisionConfiguration *collisionConfig;

  m_broadphase = new btDbvtBroadphase();
  collisionConfig = new btDefaultCollisionConfiguration();
  m_dispatcher = new btCollisionDispatcher(collisionConfig);
  m_solver = new btSequentialImpulseConstraintSolver();

  m_dynamicsWorld = new btDiscreteDynamicsWorld(
    m_dispatcher,
    m_broadphase,
    m_solver,
    collisionConfig);
  m_dynamicsWorld->setGravity(btVector3(
    m_gravity.x,
    m_gravity.y,
    m_gravity.z));

  /* Initialize objects */

  m_groundColMesh = new btTriangleMesh();
  m_ground = new Obstacle(
    "..//assets//Ground.obj",     //obj file path
    1.0f,                         //scale  
    glm::vec3(0.0f, 0.0f, 0.0f),  //position 
    m_groundColMesh);             //collider mesh
  m_ground->Initialize();
  m_dynamicsWorld->addRigidBody(m_ground->m_rigidBody);

  m_targetColMesh = new btTriangleMesh();
  m_target = new Target(
    "..//assets//Target.obj",
    1.0f,
    glm::vec3(0.0f, 4.0f, 0.0f), 
    m_targetColMesh);
  m_target->Initialize();
  m_dynamicsWorld->addRigidBody(m_target->m_rigidBody);
  
  m_dynamicsWorld->addCollisionObject(m_target->m_trigger->m_ghostObject);
  m_dynamicsWorld->getBroadphase()->getOverlappingPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());
  
  m_canColMesh = new btTriangleMesh();
  m_can = new Can(
    "..//assets//can.obj",
    1.0f,
    glm::vec3(0.0f, 3.0f, -3.0f), 
    m_canColMesh);
  m_can->Initialize();
  m_dynamicsWorld->addRigidBody(m_can->m_rigidBody);
  
  for(int i=0 ; i<m_bulletInstance ; i++)
  {
    m_bullets[i] = new Bullet("..//assets//Bb.obj", 0.06, glm::vec3(900 *(i+1), -900*(i+1), -900*(i+1)));
    m_bullets[i]->Initialize();
    m_dynamicsWorld->addRigidBody(m_bullets[i]->m_rigidBody);
  }
  
  m_gun = new Gun("..//assets//Gun.obj", 1.0);
  m_cross = new Cross("..//assets//cross.obj", 1.0);
  
  return true;
}

void World::Update(unsigned int dt)
{
  m_dynamicsWorld->stepSimulation(dt, 0.05f);

  m_gun->SetCameraTransform(m_cameraTransform);
  m_cross->SetCameraTransform(m_cameraTransform);

  m_ground->Update(dt);
  m_target->Update(dt);
  m_gun->Update(dt);
  if(m_crossRender) m_cross->Update(dt);
  m_can->Update(dt);
  
  for(int i=0 ; i<m_bulletInstance ; i++)
  {
    m_bullets[i]->Update(dt);
  }
  
  
  //------------------------------------------------
  m_hitTimer += dt;
  
  bool ifTargetHit = false;
  
  int targetCollisionNum = m_target->m_trigger->m_ghostObject->getNumOverlappingObjects();
  
  for(int i=0 ; i<targetCollisionNum ; i++)
  {
      btRigidBody *collidingBody = dynamic_cast<btRigidBody*>(m_target->m_trigger->m_ghostObject->getOverlappingObject(i));
      
      for(int j=0 ; j<m_bulletIterator ; j++)
      {
        if(collidingBody->getCompanionId() == m_bullets[j]->m_rigidBody->getCompanionId())
            ifTargetHit = true;
      }
  }
  
  if(ifTargetHit && m_hitTimer > 100) /**PLAY A "BTINNNNNNNG" SOUND**/
  {
      cout << "HIT TARGET" << endl;
      m_score += 50;
      m_hitTimer = 0.0;
  }
//---------------------------------------------
}

void World::Render()
{
  /* render all generic renderable objects */
}

void World::Render(GLint& modelMatrix, unsigned int obj)
{
  /* render select objects */

  //objects that are rendered in this function should not 
  //be rendered in the other render function

  switch(obj)
  {
    case 0:
      //render specific object with id 0
      glUniformMatrix4fv(
        modelMatrix, 
        1, 
        GL_FALSE, 
        glm::value_ptr(m_ground->GetModel()));
      m_ground->Render();
      break;
    case 1:
      glUniformMatrix4fv(
        modelMatrix, 
        1, 
        GL_FALSE, 
        glm::value_ptr(m_target->GetModel()));
      m_target->Render();
      break;
    case 2:
      glUniformMatrix4fv(
        modelMatrix, 
        1, 
        GL_FALSE, 
        glm::value_ptr(m_gun->GetModel()));
      m_gun->Render();
      
      if(m_crossRender)
      {
        glUniformMatrix4fv(
            modelMatrix, 
            1, 
            GL_FALSE, 
            glm::value_ptr(m_cross->GetModel()));
        m_cross->Render();
      }
      break;
    case 3:
        for(int i=0 ; i<m_bulletInstance ; i++)
        {
            glUniformMatrix4fv(
                modelMatrix, 
                1, 
                GL_FALSE, 
                glm::value_ptr(m_bullets[i]->GetModel()));
            m_bullets[i]->Render();
        }
      break;
    case 4:
        glUniformMatrix4fv(
            modelMatrix, 
            1, 
            GL_FALSE, 
            glm::value_ptr(m_can->GetModel()));
        m_can->Render();

      break;
    //add more cases for more objects
    default: break;
  }
}

void World::Reset()
{
  m_gameOver = false;

  //reset game stats
  m_score = 0;
  m_crossRender = true;
  m_ammoCount = 0;
}

void World::GenerateScores(string topTenList[10], bool& highScore)
{
    ifstream fin, topFin;
    topFin.open("..//assets//topScores.txt");
    
    struct TopPlayer
    {
      int score;
      string name;
    };
    
    TopPlayer leaderBoard[11];
    
    cout << endl << "YOUR SCORE: " << m_score << endl;
    
    for(int i=0 ; i<10 ; i++)
    {
       topFin >> leaderBoard[i].score >> leaderBoard[i].name;
       //cout << leaderBoard[i].score << " " << leaderBoard[i].name << endl;
    }

    //cout << m_score << ", " << leaderBoard[0].score << endl;
    if (m_score > leaderBoard[0].score)
    {
      highScore = true;
    }

    string str;
    ifstream nameFin;
    nameFin.open("..//assets//nameLog.txt");
    nameFin >> str;
    nameFin.close();
    

    leaderBoard[10].score = m_score;
    leaderBoard[10].name = str;

    
    //topScores.push_back(score);
    
    topFin.close();
    ofstream fout;
    fout.open("..//assets//topScores.txt");

    //**SORT**

    TopPlayer temp;
    for(int i=0 ; i<11 ; i++)
    {
      for(int j=i+1 ; j<11 ; j++)
      {
        if(leaderBoard[i].score < leaderBoard[j].score)
        {
          //swap
          temp = leaderBoard[i];
          leaderBoard[i] = leaderBoard[j];
          leaderBoard[j] = temp;
        }
      }
    }

    //********
    
    int rank = 1;
    cout << endl << "**TOP SCORES**" << endl;
    for(int i=0; i<10 ; i++)
    {
        stringstream ss;
        ss << rank++ << ") " << leaderBoard[i].score << " " << leaderBoard[i].name;
        cout << ss.str() << endl;
        topTenList[i] = ss.str();
        fout << leaderBoard[i].score << " " << leaderBoard[i].name << endl; 
    }
        
    fout.close();
}

int World::GetObjectCount()
{
  return m_objectCount;
}

bool World::isGameOver()
{
  return m_gameOver;
}

int World::GetScore()
{
  return m_score;
}

bool World::IsNewHighScore()
{
  return m_newHighScore;
}

string* World::GetTopTenStats()
{
  return m_topTenStats;
}

void World::createBullet(float x, float y, float z, float pitch, float yaw)
{
    m_ammoCount++;
    if(m_ammoCount > m_ammoMax) /**PLAY A CLICK SOUND**/
    {
        cout << "Ran out of Ammo!!" << endl;
        
        //end the game
        //m_score = 0;
        GenerateScores(m_topTenStats, m_newHighScore);
        m_gameOver = true;
        m_crossRender = false;
    }
    
    else /**shoot a bullet;PLAY AN AIR RIFLE POP SOUND**/
    {
        if(m_bulletIterator >= m_bulletInstance)
        m_bulletIterator = 0;
        
        glm::vec3 localForward = glm::vec3(0.0, 0.0, -1.0);
        localForward.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        localForward.y = sin(glm::radians(pitch));
        localForward.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        localForward = glm::normalize(localForward);
        btVector3 shootDir = btVector3(localForward.x,localForward.y,localForward.z);
        //m_bulletDir[m_bulletIterator] = btVector3(localForward.x,localForward.y,localForward.z);
        
        cout << "BULLET POSITION: " << x << " " << y << " "  << z << endl;
        cout << "LOOKING AT: " << localForward.x << " " << localForward.y << " " << localForward.z << endl;
        
        btTransform bulletTransform(btQuaternion::getIdentity(), btVector3(x, y, z));

        //zero ball's velocity and set ball to initial transform
        m_bullets[m_bulletIterator]->m_rigidBody->setWorldTransform(bulletTransform);
        m_bullets[m_bulletIterator]->m_rigidBody->setLinearVelocity(btVector3(0,0,0));
        m_bullets[m_bulletIterator]->m_rigidBody->setLinearVelocity(shootDir * .095);
        m_bulletIterator++;
    }
}

int World::GetAmmoCount()
{
    if(m_ammoMax - m_ammoCount > 0)
        return m_ammoMax - m_ammoCount;
    
    else
        return 0;
}