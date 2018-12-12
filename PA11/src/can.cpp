#include "can.h"

Can::Can() : PhysicsObject()
{

}

Can::Can(string filename) : PhysicsObject(filename)
{

}

Can::Can(string filename, float scale, glm::vec3 position) : PhysicsObject(filename, scale, position)
{

}

Can::Can(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh) : PhysicsObject(filename, scale, position, triMesh)
{

}

Can::~Can()
{
  delete m_renderData;
  m_children.clear();
  delete m_collider;
  m_collider = NULL;
  delete m_rigidBody;
  m_rigidBody = NULL;
}


bool Can::Initialize()
{
  cout << "CHECK CAN INITIALIZE" << endl;

  //set transform
  btTransform transform(
    btQuaternion::getIdentity(),
    btVector3(
      m_position.x,
      m_position.y,
      m_position.z));

  //create the collider
  //m_collider = new btBvhTriangleMeshShape(m_colliderMesh, false);
    m_collider = new btCylinderShape(btVector3(
            m_scale.x/2,
            m_scale.y/2,
            m_scale.z/2));

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
  //m_rigidBody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT);

  //don't delete motion state
  //delete motionState;
  //motionState = NULL;
  
  model = m_translationMatrix;

  return true;
}

void Can::Update(unsigned int dt)
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
