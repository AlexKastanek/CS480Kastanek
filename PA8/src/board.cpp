#include "board.h"

Board::Board()
{
  m_parent = NULL;
  m_renderData = new Model();
  if (!m_renderData->LoadObject())
  {
    delete m_renderData;
    exit(1);
  }

  m_position = glm::vec3(0.0f, 0.0f, 0.0f);
  m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
  m_scale = glm::vec3(1.0f, 1.0f, 1.0f);

  /*Physics*/

  //create the collider
  m_collider = new btStaticPlaneShape(btVector3(0.0f, 1.0f, 0.0f), 1);

  //create the motion state
  btDefaultMotionState *motionState = NULL;
  motionState = new btDefaultMotionState(
    btTransform(
      btQuaternion(0, 0, 0, 0),
      btVector3(0, 0, 0)
      )
    );

  //set mass and inertia
  btScalar mass(0);
  btVector3 inertia(0, 0, 0);
  m_collider->calculateLocalInertia(mass, inertia);

  //set the construction info
  btRigidBody::btRigidBodyConstructionInfo ci (
    mass,
    motionState,
    m_collider,
    inertia
    );

  //create the rigid body
  m_rigidBody = new btRigidBody(ci);

  delete motionState;

}

Board::Board(string filename)
{
  m_parent = NULL;
  m_renderData = new Model();
  if (!m_renderData->LoadObject(filename))
  {
    delete m_renderData;
    exit(1);
  }

  m_position = glm::vec3(0.0f, 0.0f, 0.0f);
  m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
  m_scale = glm::vec3(1.0f, 1.0f, 1.0f);

  /*Physics*/

  //create the collider
  m_collider = new btStaticPlaneShape(btVector3(0.0f, 1.0f, 0.0f), 1);

  //create the motion state
  btDefaultMotionState *motionState = NULL;
  motionState = new btDefaultMotionState(
    btTransform(
      btQuaternion(0, 0, 0, 0),
      btVector3(0, 0, 0)
      )
    );

  //set mass and inertia
  btScalar mass(0);
  btVector3 inertia(0, 0, 0);
  m_collider->calculateLocalInertia(mass, inertia);

  //set the construction info
  btRigidBody::btRigidBodyConstructionInfo ci (
    mass,
    motionState,
    m_collider,
    inertia
    );

  //create the rigid body
  m_rigidBody = new btRigidBody(ci);

  delete motionState;
}

Board::Board(string filename, float scale)
{
  m_parent = NULL;
  m_renderData = new Model();
  if (!m_renderData->LoadObject(filename))
  {
    delete m_renderData;
    exit(1);
  }

  m_position = glm::vec3(0.0f, 0.0f, 0.0f);
  m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
  m_scale = glm::vec3(1.0f * scale, 1.0f * scale, 1.0f * scale);

  /*Physics*/

  //create the collider
  m_collider = new btStaticPlaneShape(btVector3(0.0f, 1.0f, 0.0f), 1);

  //create the motion state
  btDefaultMotionState *motionState = NULL;
  motionState = new btDefaultMotionState(
    btTransform(
      btQuaternion(0, 0, 0, 0),
      btVector3(0, 0, 0)
      )
    );

  //set mass and inertia
  btScalar mass(0);
  btVector3 inertia(0, 0, 0);
  m_collider->calculateLocalInertia(mass, inertia);

  //set the construction info
  btRigidBody::btRigidBodyConstructionInfo ci (
    mass,
    motionState,
    m_collider,
    inertia
    );

  //create the rigid body
  m_rigidBody = new btRigidBody(ci);

  delete motionState;
}

Board::~Board()
{
  delete m_renderData;
  m_children.clear();
  delete m_collider;
  m_collider = NULL;
  delete m_rigidBody;
  m_rigidBody = NULL;
}

void Board::Update(unsigned int dt)
{
  btTransform transform;
  btScalar modelUpdate[16];

  //assign value to transform based on rigid body's new world status
  //then update model with transform
  m_rigidBody->getMotionState()->getWorldTransform(transform);
  transform.getOpenGLMatrix(modelUpdate);
  model = glm::make_mat4(modelUpdate);
}