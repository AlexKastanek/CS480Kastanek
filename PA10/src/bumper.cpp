#include "bumper.h"

Bumper::Bumper() : PhysicsObject()
{

}

Bumper::Bumper(string filename) : PhysicsObject(filename)
{

}

Bumper::Bumper(string filename, float scale, glm::vec3 position) : PhysicsObject(filename, scale, position)
{

}

Bumper::Bumper(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh, float initAngle) : PhysicsObject(filename, scale, position, triMesh)
{
  m_initialAngle = initAngle;
  m_currentAngle = m_initialAngle;
}

Bumper::~Bumper()
{
    delete m_renderData;
    m_children.clear();
    delete m_collider;
    m_collider = NULL;
    delete m_rigidBody;
    m_rigidBody = NULL;
}

bool Bumper::Initialize(btTriangleMesh *triMesh)
{
  float pi3Over2 = 3.14;

  //set transform
  btTransform transform(
    btQuaternion(m_initialAngle,0,0),
    btVector3(
      m_position.x,
      m_position.y,
      m_position.z));
  btScalar m[16];

  //rotate 90 degrees
  m_rotationMatrix = glm::rotate(
    glm::mat4(1.0f),
    (float) 1.7335,
    glm::vec3(0.0f, 1.0f, 0.0f));

  //set the scale
  m_scaleMatrix = glm::scale(
    glm::mat4(1.0),
    m_scale);

  //create the collider
  m_collider = new btBoxShape(btVector3(
    (m_scale.x) * 0.25,
    (m_scale.y) * 0.25,
    (m_scale.z) * 1));

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

  //get this origin
  btVector3 origin = m_rigidBody->getWorldTransform().getOrigin();

  //set pivot position
  float x_offset = sin(pi3Over2 + m_initialAngle) * (m_scale.x / 2);
  float z_offset = cos(pi3Over2 + m_initialAngle) * (m_scale.z / 2);
  m_pivotPosition = glm::vec3(
    origin.x() + x_offset,
    origin.y(),
    origin.z() + z_offset);

  //set inital position to correct offset
  m_position = glm::vec3(
    origin.x(),
    origin.y(),
    origin.z());
  float distanceToPivot = glm::distance(m_position, m_pivotPosition);
  
  btTransform offsetTransform(
    btQuaternion(m_initialAngle,0,0),
    btVector3(
      m_position.x + distanceToPivot * sin(m_currentAngle),
      m_position.y,
      m_position.z + distanceToPivot * cos(m_currentAngle)));
  
  m_rigidBody->getMotionState()->setWorldTransform(offsetTransform);
  
  //apply all transformations
  offsetTransform.getOpenGLMatrix(m);
  model = glm::make_mat4(m) * m_rotationMatrix * m_scaleMatrix;

  return true;
}

void Bumper::Update(unsigned int dt)
{
  btTransform transform;
  btScalar modelUpdate[16];


  //get the new transform of the rigid body
  m_rigidBody->getMotionState()->getWorldTransform(transform);
  
  //apply all transformations
  transform.getOpenGLMatrix(modelUpdate);
  model = glm::make_mat4(modelUpdate) * m_scaleMatrix;

}

