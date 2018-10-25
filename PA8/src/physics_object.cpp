#include "physics_object.h"

PhysicsObject::PhysicsObject()
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

  //TODO: Allocate physics stuff! (lookup function definitions and parameters)
}

PhysicsObject::PhysicsObject(string filename)
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
}

PhysicsObject::PhysicsObject(string filename, float scale)
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
}

PhysicsObject::~PhysicsObject()
{
  delete m_renderData;
  m_children.clear();
}

void PhysicsObject::Update(unsigned int dt)
{
  btTransform transform;
  btScalar modelUpdate[16];

  //assign value to transform based on rigid body's new world status
  //then update model with transform
  m_rigidBody->getMotionState()->getWorldTransform(transform);
  transform.getOpenGLMatrix(modelUpdate);
  model = glm::make_mat4(modelUpdate);
}