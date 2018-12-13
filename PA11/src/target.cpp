#include "target.h"

Target::Target() : PhysicsObject()
{

}

Target::Target(string filename) : PhysicsObject(filename)
{
    m_translateMod = 0;
}

Target::Target(string filename, float scale, glm::vec3 position) : PhysicsObject(filename, scale, position)
{
    m_translateMod = 0;
}

Target::Target(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh, char dir) : PhysicsObject(filename, scale, position, triMesh)
{
    m_translateMod = 0;
    m_direction = dir;
}

Target::~Target()
{
  delete m_renderData;
  m_children.clear();
  delete m_collider;
  m_collider = NULL;
  delete m_rigidBody;
  m_rigidBody = NULL;
}


bool Target::Initialize()
{
  cout << "CHECK Target INITIALIZE" << endl;

  //set transform
  btTransform transform(
    btQuaternion::getIdentity(),
    btVector3(
      m_position.x,
      m_position.y,
      m_position.z));

  //create the collider
  m_collider = new btBvhTriangleMeshShape(m_colliderMesh, false);

  //create the motion state
  m_motionState = new btDefaultMotionState(transform);

  //set mass and inertia
  btScalar mass(0.0f);
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
  m_rigidBody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);

  //don't delete motion state
  //delete motionState;
  //motionState = NULL;
  
  //Initialize Trigger  
  m_trigger = new TriggerObject(
      glm::vec3(0.001f, 0.001f, 0.001f) * m_scale,
      glm::vec3(m_position.x, m_position.y, m_position.z),
      m_collider
  );
  m_trigger->Initialize();
  
  model = m_translationMatrix;

  return true;
}

void Target::Update(unsigned int dt)
{
    btTransform transform, newTransform;
    btScalar modelUpdate[16];
    btVector3 origin = m_rigidBody->getWorldTransform().getOrigin();
    btMatrix3x3 basis = m_rigidBody->getWorldTransform().getBasis();

    
    m_position = glm::vec3(origin.x(), origin.y(), origin.z());
     
//     if(m_position.z >= 5.0)
//     {
//         m_direction = false;
//     }
//     else if(m_position.z <= -5.0)
//     {
//         m_direction = true;
//     }
//     
//     if(m_direction)
//         m_position.z += .06;
//     else
//         m_position.z -= .06;
    
    if(m_position.z >= 5 && m_position.y <= 4)
        m_direction = 'u';
    else if(m_position.z >= 5 && m_position.y >= 9)
        m_direction = 'l';
    else if(m_position.z <= -5 && m_position.y >= 9)
        m_direction = 'd';
    else if(m_position.z <= -5 && m_position.y <= 4)
        m_direction = 'r';
    
    
    float moveMod = .07;
    if(m_direction == 'u')
        m_position.y += moveMod * (dt + 1) * 0.1f;
    else if(m_direction == 'l')
        m_position.z -= moveMod * (dt + 1) * 0.1f;
    else if(m_direction == 'd')
        m_position.y -= moveMod * (dt + 1) * 0.1f;
    else if(m_direction == 'r')
        m_position.z += moveMod * (dt + 1) * 0.1f;
    
    
    //translate the collision box
    btVector3 newOrigin = btVector3(m_position.x, m_position.y, m_position.z);
    btQuaternion newRotation = btQuaternion::getIdentity();
    
    newTransform.setOrigin(newOrigin);
    newTransform.setBasis(basis);
    
    m_rigidBody->getMotionState()->setWorldTransform(newTransform);
    
    //translate the trigger
    m_trigger->transformTrigger(newTransform);

    //set the scale
    m_scaleMatrix = glm::scale(
            glm::mat4(1.0),
            m_scale);

    //assign value to transform based on rigid body's new world status
    //then update model with transform
    m_rigidBody->getMotionState()->getWorldTransform(transform);
    newTransform.getOpenGLMatrix(modelUpdate);
    model = glm::make_mat4(modelUpdate) * m_scaleMatrix;
}
