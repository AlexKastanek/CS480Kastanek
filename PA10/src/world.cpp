#include "world.h"
#include "graphics.h"

World::World() : Physics()
{
  moveForce = 0.5f;

  /*
  m_boardSpecular = 1.0f;
  m_ballSpecular = 1.0f;
  m_flipperRightSpecular = 1.0f;
  m_flipperLeftSpecular = 1.0f;
  m_cylinderSpecular = 1.0f;
  */
}

World::World(glm::vec3 gravity) : Physics(gravity)
{
  moveForce = 0.5f;

  /*
  m_boardSpecular = 1.0f;
  m_ballSpecular = 1.0f;
  m_flipperRightSpecular = 1.0f;
  m_flipperLeftSpecular = 1.0f;
  m_cylinderSpecular = 1.0f;
  */
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

  boardMesh = new btTriangleMesh();
  m_board = new Board("..//assets//Board.obj", 100.0f, glm::vec3(0.0, 0.0, 0.0), boardMesh);
  m_board->Initialize(boardMesh);
  m_dynamicsWorld->addRigidBody(m_board->m_rigidBody);

  m_ball = new Ball("..//assets//Ball.obj", 3.0f, glm::vec3(-45.5f, 20.0f, 0.0f));
  m_ball->Initialize();  
  m_dynamicsWorld->addRigidBody(m_ball->m_rigidBody);

  m_flipperLeft = new Flipper("..//assets//Flipper.obj", 10.0f, glm::vec3(19.0f, 2.5f, -50.0f), false);
  m_flipperLeft->Initialize();
  m_dynamicsWorld->addRigidBody(m_flipperLeft->m_rigidBody);

  m_flipperRight = new Flipper("..//assets//Flipper.obj", 10.0f, glm::vec3(-19.0f, 2.5f, -50.0f), true);
  m_flipperRight->Initialize();
  m_dynamicsWorld->addRigidBody(m_flipperRight->m_rigidBody);

  m_plunger = new Plunger("..//assets//Plunger.obj", 10.0f, glm::vec3(-45.0f, 2.5f, -60.0f));
  m_plunger->Initialize();
  m_dynamicsWorld->addRigidBody(m_plunger->m_rigidBody);

  cylMesh = new btTriangleMesh();
  m_cylinder = new Cylinder("..//assets//cylinder.obj", 10.0f, glm::vec3(0.0f, 2.0f, 25.0f), cylMesh);
  m_cylinder->Initialize(cylMesh);

  m_dynamicsWorld->addRigidBody(m_cylinder->m_rigidBody);

  m_launchBarrier = new LaunchBarrier("..//assets//LaunchBarrier.obj", 10.0, glm::vec3(-39.0f, 2.5f, -10.0f));
  m_launchBarrier->Initialize();
  m_dynamicsWorld->addRigidBody(m_launchBarrier->m_rigidBody);

  m_launchArea = new TriggerObject(
    glm::vec3(1.0f, 10.0f, 80.0f),
    glm::vec3(-45.5f, 1.0f, -10.0f));
  m_launchArea->Initialize();
  m_dynamicsWorld->addCollisionObject(m_launchArea->m_ghostObject);
  m_dynamicsWorld->getBroadphase()->getOverlappingPairCache()->
    setInternalGhostPairCallback(new btGhostPairCallback());
    
  bumpMeshL = new btTriangleMesh();
  m_bumperL = new Bumper("..//assets//Bumper.obj", 12.0f, glm::vec3(15.0f, 2.0f, -25.0f), bumpMeshL, 1.0f);
  m_bumperL->Initialize(bumpMeshL);
  m_dynamicsWorld->addRigidBody(m_bumperL->m_rigidBody);
  
  createWalls();

  return true;
}

void World::Update(unsigned int dt)
{
  /*
  if (m_ball->m_rigidBody->checkCollideWith(m_launchArea->m_collisionObject))
  {
    cout << "COLLIDING" << endl;
  }
  else
  {
    cout << "NOT COLLIDING" << endl;
  }
  */
  /*int numManifolds = m_dynamicsWorld->getDispatcher()->getNumManifolds();
  cout << numManifolds << endl;*/


  m_dynamicsWorld->stepSimulation(dt, 0.5f);
  
  m_board->Update(dt);
  m_ball->Update(dt);
  m_flipperRight->Update(dt);
  m_flipperLeft->Update(dt);
  m_plunger->Update(dt);
  m_cylinder->Update(dt);
  m_launchBarrier->Update(dt); 
  m_bumperL->Update(dt);

  /*check if ball is inside launch area*/

  bool collidingWithBall = false;

  //get amount of objects inside launch area
  int launchAreaCollisionAmount = m_launchArea->m_ghostObject->getNumOverlappingObjects();

  //loop through each object
  for (int i = 0; i < launchAreaCollisionAmount; i++)
  {
    //get the object
    btRigidBody *collidingBody = dynamic_cast<btRigidBody*>(
      m_launchArea->m_ghostObject->getOverlappingObject(i));

    //if this object is the ball, colliding with ball is true
    if (collidingBody->getCompanionId() == m_ball->m_rigidBody->getCompanionId())
    {
      collidingWithBall = true;
    }
  }

  //if colliding with ball
  if (collidingWithBall)
  {
    /*
    //cout << "COLLIDING WITH BALL" << endl;

    //get the ball's position
    btTransform ballTransform;
    m_ball->m_rigidBody->getMotionState()->getWorldTransform(ballTransform);
    btVector3 position = ballTransform.getOrigin();

    //if this position is not centered between the two walls
    if (position.x() > -46.0 && position.x() < -44.0)
    {
      //cout << "IN RANGE" << endl;
      //if this ball was not in range in the previous frame
      if (!m_ballInLaunchRange)
      {
        //reset velocity
        cout << "RESETTING BALL VELOCITY" << endl;
        m_ball->m_rigidBody->setLinearVelocity(btVector3(0,0,0));
      }

      m_ballInLaunchRange = true;
    }
    */

    //if this ball was not in range in the previous frame
    if (!m_ballInLaunchRange)
    {
      cout << "RESETTING BALL VELOCITY" << endl;
      m_ball->m_rigidBody->setLinearVelocity(btVector3(0,0,0));
      m_ball->CenterInLaunchArea();
    }
    m_ballInLaunchRange = true;
    
    /*
    else if (position.x() < -46.0)
    {
      cout << "TO THE RIGHT" << endl;
      m_ballInLaunchRange = false;
      m_ball->m_rigidBody->applyCentralImpulse(btVector3(0.0001,0,0));
    }
    else
    {
      cout << "TO THE LEFT" << endl;
      m_ballInLaunchRange = false;
      m_ball->m_rigidBody->applyCentralImpulse(btVector3(-0.0001,0,0));
    }
    else
    {
      //set ball in range to false
      m_ballInLaunchRange = false;
    }
    */

    //keep ball inside launch area
    m_ball->m_rigidBody->setLinearFactor(btVector3(0,1,1));
  }
  //if not in launch area, let forces be applied to the ball
  else
  {
    //cout << "NOT COLLIDING WITH BALL" << endl;
    m_ball->m_rigidBody->setLinearFactor(btVector3(1,1,1));
    m_ballInLaunchRange = false;
  }
}

void World::Render(GLint& modelMatrix, char obj)
{
  switch(obj)
  {
    case 't':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_board->GetModel()));
      m_board->Render();
      break;
    case 'b':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_ball->GetModel()));
      m_ball->Render();
      break;
    case 'f':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_flipperRight->GetModel()));
      m_flipperRight->Render();
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_flipperLeft->GetModel()));
      m_flipperLeft->Render();
      break;
    case 'p':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_plunger->GetModel()));
      m_plunger->Render();
      break;
    case 'c':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cylinder->GetModel()));
      m_cylinder->Render();
      break; 
    case 'l':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_launchBarrier->GetModel()));
      m_launchBarrier->Render();
      break;
    case 'u':
      glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_bumperL->GetModel()));
      m_bumperL->Render();
      break;  
    default: break;
  }
    
  /*
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_board->GetModel()));
  m_board->Render();
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_ball->GetModel()));
  m_ball->Render();
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_flipperRight->GetModel()));
  m_flipperRight->Render();
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_flipperLeft->GetModel()));
  m_flipperLeft->Render();
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cylinder->GetModel()));
  m_cylinder->Render();
  */
}

Board& World::GetBoard()
{
  return *m_board;
}

Ball& World::GetBall()
{
  return *m_ball;
}

Flipper& World::GetFlipperRight()
{
  return *m_flipperRight;
}

Flipper& World::GetFlipperLeft()
{
  return *m_flipperLeft;
}

Cylinder& World::GetCylinder()
{
  return *m_cylinder;
}

/*
float World::GetBoardSpecular()
{
  return m_boardSpecular;
}

float World::GetBallSpecular()
{
  return m_ballSpecular;
}

float World::GetFlipperRightSpecular()
{
  return m_flipperRightSpecular;
}

float World::GetFlipperLeftSpecular()
{
  return m_flipperLeftSpecular;
}

float World::GetCylinderSpecular()
{
  return m_cylinderSpecular;
}

void World::SetBoardSpecular(float boardSpecular)
{
  m_boardSpecular = boardSpecular;
}

void World::SetBallSpecular(float ballSpecular)
{
  m_ballSpecular = ballSpecular;
}

void World::SetFlipperRightSpecular(float flipperRightSpecular)
{
  m_flipperRightSpecular = flipperRightSpecular;
}

void World::SetFlipperLeftSpecular(float flipperLeftSpecular)
{
  m_flipperLeftSpecular = flipperLeftSpecular;
}

void World::SetCylinderSpecular(float cylinderSpecular)
{
  m_cylinderSpecular = cylinderSpecular;
}
*/

void World::moveFlipperUp()
{
  //cout << "move flipper up" << endl;
   m_flipperRight -> m_rigidBody -> applyCentralImpulse(btVector3(0.0, 0.0, moveForce));
}

void World::moveFlipperDown()
{
  //cout << "move flipper down" << endl;
   m_flipperRight -> m_rigidBody -> applyCentralImpulse(btVector3(0.0, 0.0, moveForce * -1));

}

void World::moveFlipperRight()
{
  //cout << "move flipper right" << endl;
   m_flipperRight -> m_rigidBody -> applyCentralImpulse(btVector3(moveForce * -1, 0.0, 0.0));
}

void World::moveFlipperLeft()
{
  //cout << "move flipper left" << endl;
   m_flipperRight -> m_rigidBody -> applyCentralImpulse(btVector3(moveForce, 0.0, 0.0));
}

void World::FlipRight()
{
  m_flipperRight->Flip();
}

void World::FlipLeft()
{
  m_flipperLeft->Flip();
}

void World::PullPlunger()
{
  m_plunger->Pull();
}

void World::ReleasePlunger()
{
  m_plunger->Release();
}

void World::createWalls()
{
  //bottom collision wall
  m_bottomWall = new btStaticPlaneShape(btVector3(0, 0, 1), 1);
  m_bottomWallMotion = NULL;
  m_bottomWallMotion = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,0,-70)));
  btRigidBody::btRigidBodyConstructionInfo bottomCI(0, m_bottomWallMotion, m_bottomWall, btVector3(0,0,0));
  m_bottomWallRigid = new btRigidBody(bottomCI);
  m_bottomWallRigid -> setActivationState(DISABLE_DEACTIVATION);
  m_dynamicsWorld->addRigidBody(m_bottomWallRigid);
  
  //left collision wall
  m_leftWall = new btStaticPlaneShape(btVector3(-1, 0, 0), 1);
  m_leftWallMotion = NULL;
  m_leftWallMotion = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(50,0,0)));
  btRigidBody::btRigidBodyConstructionInfo leftCI(0, m_leftWallMotion, m_leftWall, btVector3(0,0,0));
  m_leftWallRigid = new btRigidBody(leftCI);
  m_leftWallRigid -> setActivationState(DISABLE_DEACTIVATION);
  m_dynamicsWorld->addRigidBody(m_leftWallRigid);
  
  //right collision wall
  m_rightWall = new btStaticPlaneShape(btVector3(1, 0, 0), 1);
  m_rightWallMotion = NULL;
  m_rightWallMotion = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(-50,0,0)));
  btRigidBody::btRigidBodyConstructionInfo rightCI(0, m_rightWallMotion, m_rightWall, btVector3(0,0,0));
  m_rightWallRigid = new btRigidBody(rightCI);
  m_rightWallRigid -> setActivationState(DISABLE_DEACTIVATION);
  m_dynamicsWorld->addRigidBody(m_rightWallRigid);
  
  //top collision wall
  m_topWall = new btStaticPlaneShape(btVector3(0, 0, -1), 1);
  m_topWallMotion = NULL;
  m_topWallMotion = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,0,90)));
  btRigidBody::btRigidBodyConstructionInfo topCI(0, m_topWallMotion, m_topWall, btVector3(0,0,0));
  m_topWallRigid = new btRigidBody(topCI);
  m_topWallRigid -> setActivationState(DISABLE_DEACTIVATION);
  m_dynamicsWorld->addRigidBody(m_topWallRigid);
  
  //collision wall to keep objects from flying out 
  m_lid = new btStaticPlaneShape(btVector3(0, -1, 0), 1);
  m_lidMotion = NULL;
  m_lidMotion = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,7,0)));
  btRigidBody::btRigidBodyConstructionInfo lidCI(0, m_lidMotion, m_lid, btVector3(0,0,0));
  m_lidRigid = new btRigidBody(lidCI);
  m_lidRigid -> setActivationState(DISABLE_DEACTIVATION);
  m_dynamicsWorld->addRigidBody(m_lidRigid);
}