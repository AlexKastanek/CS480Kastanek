#include "world.h"

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

  m_board = new Board("..//assets//Board.obj", 100.0f);
  m_board->Initialize();
  m_dynamicsWorld->addRigidBody(m_board->m_rigidBody);

  m_ball = new Ball("..//assets//Ball.obj", 3.0f, glm::vec3(0.0f, 100.0f, 0.0f));
  m_ball->Initialize();  
  m_dynamicsWorld->addRigidBody(m_ball->m_rigidBody);

  m_flipperRight = new Flipper("..//assets//Flipper.obj", 10.0f, glm::vec3(0.0f, 2.5f, -50.0f));
  m_flipperRight->Initialize();
  m_dynamicsWorld->addRigidBody(m_flipperRight->m_rigidBody);

  

  return true;
}

void World::Update(unsigned int dt)
{
  //cout << "entered world update function" << endl;

  m_dynamicsWorld->stepSimulation(dt, 1);

  //cout << "updating objects" << endl;
  m_board->Update(dt);
  m_ball->Update(dt);
  m_flipperRight->Update(dt);
  //cout << "finished updating objects" << endl;

  if (!flipped)
  {
    m_flipperRight->Flip();
    flipped = true;
  }
}

void World::Render(GLint& modelMatrix)
{
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_board->GetModel()));
  m_board->Render();
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_ball->GetModel()));
  m_ball->Render();
  glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(m_flipperRight->GetModel()));
  m_flipperRight->Render();
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