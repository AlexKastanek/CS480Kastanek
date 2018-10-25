#include "ball.h"

Ball::Ball() : PhysicsObject()
{

}

Ball::Ball(string filename) : PhysicsObject(filename)
{

}

Ball::Ball(string filename, float scale, glm::vec3 position) : PhysicsObject(filename, scale, position)
{

}

Ball::~Ball()
{
  delete m_renderData;
  m_children.clear();
  delete m_collider;
  m_collider = NULL;
  delete m_rigidBody;
  m_rigidBody = NULL;
}

bool Ball::Initialize()
{
  cout << "CHECK BALL INITIALIZE" << endl;

  //create the collider
  m_collider = new btSphereShape(btScalar(0.5f));

  //create with correct transform info
  //create the motion state
  /*
  btDefaultMotionState *motionState = NULL;
  motionState = new btDefaultMotionState(
    btTransform(
      btQuaternion(0, 0, 0, 0),
      btVector3(0, 0, 0)));
  */
  btDefaultMotionState *motionState = NULL;
  motionState = new btDefaultMotionState();

  //set mass and inertia
  btScalar mass(1);
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

  //don't delete motion state
  //delete motionState;
  //motionState = NULL;

  cout << m_position.y << endl;

  //set the initial translation
  /*
  m_translationMatrix = glm::translate(
    glm::mat4(1.0f),
    m_position);
  model = m_translationMatrix;
  */

  return true;
}

void Ball::Update(unsigned int dt)
{
  btTransform transform;
  btScalar modelUpdate[16];

  //set the scale
  m_scaleMatrix = glm::scale(
    glm::mat4(1.0),
    m_scale);

  //assign value to transform based on rigid body's new world status
  //then update model with transform
  m_rigidBody->getMotionState()->getWorldTransform(transform);
  
  transform.getOpenGLMatrix(modelUpdate);
  model = glm::make_mat4(modelUpdate) * m_scaleMatrix;
}