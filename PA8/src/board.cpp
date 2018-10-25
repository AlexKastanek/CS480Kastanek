#include "board.h"

Board::Board() : PhysicsObject()
{
  cout << "CHECK BOARD CONSTRUCTOR" << endl;

  /*

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

  */

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
  motionState = NULL;
}

Board::Board(string filename) : PhysicsObject(filename)
{
  cout << "CHECK BOARD PARAMETERIZED CONSTRUCTOR 1" << endl;

  /*

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

  */

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
  motionState = NULL;
}

Board::Board(string filename, float scale) : PhysicsObject(filename, scale)
{
  cout << "CHECK BOARD PARAMETERIZED CONSTRUCTOR 2" << endl;

  /*

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

  */

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
  motionState = NULL;
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
  cout << "CHECK BOARD UPDATE" << endl;

  btTransform transform;
  btScalar modelUpdate[16];
  const btMotionState* motionState = m_rigidBody->getMotionState();

  //assign value to transform based on rigid body's new world status
  //then update model with transform
  motionState->getWorldTransform(transform);
  
  cout << "check 1" << endl;
  transform.getOpenGLMatrix(modelUpdate);
  cout << "check 2" << endl;
  model = glm::make_mat4(modelUpdate);

  cout << "CHECK BOARD UPDATE FINISHED" << endl;
}