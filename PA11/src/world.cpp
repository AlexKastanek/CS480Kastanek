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

  return true;
}

void World::Update(unsigned int dt)
{
  m_dynamicsWorld->stepSimulation(dt, 0.05f);
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
    case '0':
      //render specific object with id 0
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
}

void World::GenerateScores(string topTenList[10], bool& highScore)
{
    ifstream fin, topFin;
    fin.open("..//assets//scoreLog.txt");
    topFin.open("..//assets//topScores.txt");
    
    struct TopPlayer
    {
      int score;
      string name;
    };
    
    int score = 0;
    
    TopPlayer leaderBoard[11];
    
    while(!fin.eof())
        fin >> score;
    
    cout << endl << "YOUR SCORE: " << score << endl;
    
    for(int i=0 ; i<10 ; i++)
    {
       topFin >> leaderBoard[i].score >> leaderBoard[i].name;
       //cout << leaderBoard[i].score << " " << leaderBoard[i].name << endl;
    }

    cout << score << ", " << leaderBoard[0].score << endl;
    if (score > leaderBoard[0].score)
    {
      highScore = true;
    }

    string str;
    ifstream nameFin;
    nameFin.open("..//assets//nameLog.txt");
    nameFin >> str;
    nameFin.close();
    

    leaderBoard[10].score = score;
    leaderBoard[10].name = str;

    
    //topScores.push_back(score);
    
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
        
    fin.close();
    topFin.close();
    fout.close();
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