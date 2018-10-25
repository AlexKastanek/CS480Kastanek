#include "physics.h"

Physics::Physics()
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
  m_dynamicsWorld->setGravity(btVector3(0, -9.81, 0));

  delete collisionConfig;
  collisionConfig = NULL;
}

Physics::Physics(glm::vec3 gravity)
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
    gravity.x,
    gravity.y,
    gravity.z));

  delete collisionConfig;
  collisionConfig = NULL;
}

Physics::~Physics()
{
  delete m_broadphase;
  m_broadphase = NULL;
  delete m_dispatcher;
  m_dispatcher = NULL;
  delete m_solver;
  m_solver = NULL;
  delete m_dynamicsWorld;
  m_dynamicsWorld = NULL;
}

void Physics::Update(unsigned int dt)
{
  m_dynamicsWorld->stepSimulation(dt, 10);
}

/*
void Physics::AddRigidBody(btRigidBody* rigidBody)
{
  m_dynamicsWorld->addRigidBody(
    rigidBody
    );
}
*/