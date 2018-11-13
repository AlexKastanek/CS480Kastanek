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

Bumper::Bumper(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh, float initAngle, bool flipped) : PhysicsObject(filename, scale, position, triMesh)
{
  m_initialAngle = initAngle;
  m_currentAngle = m_initialAngle;
  m_flipped = flipped;
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
    cout << "CHECK Bumper INITIALIZE" << endl;

    btTransform transform(
            btQuaternion::getIdentity(),
            btVector3(
                    m_position.x,
                    m_position.y,
                    m_position.z));
    btScalar m[16];

    m_translationMatrix = glm::translate(
            glm::mat4(1.0f),
            m_position);

    //create the collider
    m_collider = new btBvhTriangleMeshShape(triMesh, false);

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
    
   ci.m_additionalDamping = true;

    //create the rigid body
    m_rigidBody = new btRigidBody(ci);
    m_rigidBody->setActivationState(DISABLE_DEACTIVATION);
    m_rigidBody->setRestitution(0.1);//elasticity!!!
    //m_rigidBody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT);

    model = m_translationMatrix;

    return true;
}

void Bumper::Update(unsigned int dt)
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

