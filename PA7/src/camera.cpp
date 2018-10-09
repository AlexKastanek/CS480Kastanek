#include "camera.h"

Camera::Camera()
{
  m_position = glm::vec3(0.0, 0.0, -16.0);
  m_velocity = glm::vec3(0.0, 0.0, 0.0);

  m_moveSpeed = 0.1f;
}

Camera::~Camera()
{

}

bool Camera::Initialize(int w, int h)
{
  //--Init the view and projection matrices
  //  if you will be having a moving camera the view matrix will need to more dynamic
  //  ...Like you should update it before you render more dynamic 
  //  for this project having them static will be fine
  view = glm::lookAt( m_position,                 //Eye Position
                      glm::vec3(0.0, 0.0, 0.0),   //Focus point
                      glm::vec3(0.0, 1.0, 0.0));  //Positive Y is up

  projection = glm::perspective( 45.0f, //the FoV typically 90 degrees is good which is what this is set to
                                 float(w)/float(h), //Aspect Ratio, so Circles stay Circular
                                 0.01f, //Distance to the near plane, normally a small value like this
                                 100.0f); //Distance to the far plane, 
  return true;
}

void Camera::Update(unsigned int dt)
{
  m_position += m_velocity;

  view = glm::lookAt( m_position,                 //Eye Position
                      glm::vec3(0.0, 0.0, 0.0),   //Focus point
                      glm::vec3(0.0, 1.0, 0.0));  //Positive Y is up
}

glm::mat4 Camera::GetProjection()
{
  return projection;
}

glm::mat4 Camera::GetView()
{
  return view;
}

glm::vec3 Camera::GetPosition()
{
  return m_position;
}

glm::vec3 Camera::GetVelocity()
{
  return m_velocity;
}

float Camera::GetMoveSpeed()
{
  return m_moveSpeed;
}

float Camera::GetPositionX()
{
  return m_position.x;
}

float Camera::GetPositionY()
{
  return m_position.y;
}

float Camera::GetPositionZ()
{
  return m_position.z;
}

float Camera::GetVelocityX()
{
  return m_velocity.x;
}

float Camera::GetVelocityY()
{
  return m_velocity.y;
}

float Camera::GetVelocityZ()
{
  return m_velocity.z;
}

void Camera::SetPosition(glm::vec3 position)
{
  m_position = position;
}

void Camera::SetPosition(float x, float y, float z)
{
  m_position = glm::vec3(x, y, z);
}

void Camera::SetVelocity(glm::vec3 velocity)
{
  m_velocity = velocity;
}

void Camera::SetVelocity(float x, float y, float z)
{
  m_velocity = glm::vec3(x, y, z);
}

void Camera::SetMoveSpeed(float moveSpeed)
{
  m_moveSpeed = moveSpeed;
}

void Camera::SetPositionX(float x)
{
  m_position.x = x;
}

void Camera::SetPositionY(float y)
{
  m_position.y = y;
}

void Camera::SetPositionZ(float z)
{
  m_position.z = z;
}

void Camera::SetVelocityX(float x)
{
  m_velocity.x = x * m_moveSpeed;
}

void Camera::SetVelocityY(float y)
{
  m_velocity.y = y * m_moveSpeed;
}

void Camera::SetVelocityZ(float z)
{
  m_velocity.z = z * m_moveSpeed;
}
