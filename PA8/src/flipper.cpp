#include "flipper.h"

Flipper::Flipper() : PhysicsObject()
{
  m_left = false;
  m_flipping = false;
  m_resetting = false;

  m_initialAngle = -0.785f; //pi/4
  m_flipAngleStep = 0.005f;
  m_resetAngleStep = -0.001f;

  m_pivotPosition = glm::vec3(-0.5f, 0.0f, 0.0f);
}

Flipper::Flipper(string filename) : PhysicsObject(filename)
{
  m_left = false;
  m_flipping = false;
  m_resetting = false;

  m_initialAngle = -0.785f;
  m_flipAngleStep = 0.005f;
  m_resetAngleStep = -0.001f;

  m_pivotPosition = glm::vec3(-0.5f, 0.0f, 0.0f);
}

Flipper::Flipper(string filename, float scale, glm::vec3 position, bool left) : PhysicsObject(filename, scale, position)
{
  m_left = left;
  m_flipping = false;
  m_resetting = false;

  m_initialAngle = -0.785f;
  m_flipAngleStep = 0.005f;
  m_resetAngleStep = -0.001f;

  m_pivotPosition = glm::vec3(-0.5f, 0.0f, 0.0f);
}

Flipper::~Flipper()
{
  delete m_renderData;
  m_children.clear();
  delete m_collider;
  m_collider = NULL;
  delete m_rigidBody;
  m_rigidBody = NULL;
}

bool Flipper::Initialize()
{
  cout << "CHECK FLIPPER INITIALIZE" << endl;

  btTransform transform(
    btQuaternion::getIdentity(),
    btVector3(
      m_position.x,
      m_position.y,
      m_position.z));
  btScalar m[16];

  //left flipper is opposite angle and steps
  if (m_left)
  {
    m_initialAngle *= -1;
    m_flipAngleStep *= -1;
    m_resetAngleStep *= -1;
  }

  //set translation
  m_translationMatrix = glm::translate(
    glm::mat4(1.0f),
    m_position);

  //set the scale
  m_scaleMatrix = glm::scale(
    glm::mat4(1.0),
    m_scale);

  //create the collider
  m_collider = new btBoxShape(btVector3(
    (m_scale.x) * 1,
    (m_scale.y) * 0.25,
    (m_scale.z) * 0.25));

  //create the motion state
  m_motionState = new btDefaultMotionState(transform);

  //set mass and inertia
  btScalar mass(0.1f);
  btVector3 inertia(0, 0, 0);
  m_collider->calculateLocalInertia(mass, inertia);

  //set the construction info
  btRigidBody::btRigidBodyConstructionInfo ci (
    mass,
    m_motionState,
    m_collider,
    inertia
    );

  //create the rigid body
  m_rigidBody = new btRigidBody(ci);
  m_rigidBody->setActivationState(DISABLE_DEACTIVATION);
  m_rigidBody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT);

  model = m_translationMatrix;

  cout << "FINISHED FLIPPER INITIALIZE" << endl;

  return true;
}

void Flipper::Update(unsigned int dt)
{
  btTransform transform;
  btTransform* newTransform;
  btScalar modelUpdate[16];

  btMatrix3x3 basis = m_rigidBody->getWorldTransform().getBasis();
  btQuaternion rotation;
  basis.getRotation(rotation);
  btVector3 axis = rotation.getAxis();
  btVector3 offset = btVector3(
    m_pivotPosition.x * axis.getX(),
    m_pivotPosition.y * axis.getY(),
    m_pivotPosition.z * axis.getZ());

  m_rigidBody->translate(offset);

  if (m_flipping)
  {
    //set newTransform to next flip step
  }
  else if (m_resetting)
  {
    //set newTransform to next reset step
  }
  else
  {
    m_initialAngle += m_flipAngleStep;

    //set newTransform to initial
    /*
    btTransform newTransform(
    btQuaternion(m_initialAngle, 0, 0),
    btVector3(
      m_position.x,
      m_position.y,
      m_position.z));
    */

    basis *= btMatrix3x3(btQuaternion(m_initialAngle, 0, 0));

    newTransform = new btTransform(basis, btVector3(
      m_position.x,
      m_position.y,
      m_position.z));

    //set the rigid body's new basis
    m_rigidBody->getMotionState()->setWorldTransform(*newTransform);
    //m_rigidBody->getMotionState()->getWorldTransform().setBasis(basis);
  }

  //btTransform newTransform(btQuaternion(m_initialAngle, 0, 0), btVector3(0,0,0));
  newTransform->setOrigin(btVector3(0,0,0));
  offset = *newTransform * offset;
  m_rigidBody->translate(offset * -1);

  //assign value to transform based on rigid body's new world status
  //then update model with transform
  m_rigidBody->getMotionState()->getWorldTransform(transform);
  
  transform.getOpenGLMatrix(modelUpdate);
  model = glm::make_mat4(modelUpdate) * m_scaleMatrix;
  //model[3].y = 3.0f;
  
}

void Flipper::Flip()
{
  float x = 0.0f;
  float y = -5.0f;
  float z = 0.0f;
  
  //m_rigidBody->applyCentralImpulse(btVector3(.0, 0.0, 6.0));

  m_rigidBody->applyTorqueImpulse(btVector3(x,y,z));
  //m_rigidBody->getWorldTransform()*btVector3(x,y,z);
  //m_rigidBody->applyTorqueImpulse(btVector3(x,y,z));
}
