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

  delete collisionConfig;
  collisionConfig = NULL;

  m_board = new Board("..//assets//Board.obj", 13.0f);
  m_board->Initialize();
  m_dynamicsWorld->addRigidBody(m_board->m_rigidBody);

  return true;
}

void World::Update(unsigned int dt)
{
  m_dynamicsWorld->stepSimulation(dt, 10);

  m_board->Update(dt);
}

void World::Render()
{
  m_board->Render();
}

Board& World::GetBoard()
{
  return *m_board;
}