#include "camera.h"

Camera::Camera()
{
  m_position = glm::vec3(0.0, 0.0, -16.0);
  m_velocity = glm::vec3(0.0, 0.0, 0.0);
  m_focusPoint = glm::vec3(0.0, 0.0, 0.0);

  m_moveSpeed = 0.1f;
  m_maxHeight = 3.0f;
  m_moveAngleHrzt = -M_PI;
  m_moveAngleVert = -M_PI/2;

  m_mode = MODE_FOCUS;
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
                      m_focusPoint,               //Focus point
                      glm::vec3(0.0, 1.0, 0.0));  //Positive Y is up

  projection = glm::perspective( 45.0f, //the FoV typically 90 degrees is good which is what this is set to
                                 float(w)/float(h), //Aspect Ratio, so Circles stay Circular
                                 0.01f, //Distance to the near plane, normally a small value like this
                                 10000.0f); //Distance to the far plane, 
  return true;
}

void Camera::Update(unsigned int dt)
{
  if (m_mode == MODE_FOCUS)
  {
    float translateMultiplier = 50000;
    float radius = glm::distance(m_position, m_focusPoint);
    float xzRadius = glm::distance(glm::vec2(m_position.x, m_position.z),
                                   glm::vec2(m_focusPoint.x, m_focusPoint.z));
    //float xPercentage, zPercentage;

    //int piCount = abs((int)(m_moveAngleHrzt / M_PI)) + 1;
    //cout << piCount << endl;

    //float angleToPi = M_PI - abs(abs(m_moveAngleHrzt) - (piCount * M_PI));
    //cout << angleToPi << endl;

    //xPercentage = angleToPi / M_PI;
    //zPercentage = 1 - xPercentage;
    /*
    xPercentage = abs(((m_moveAngleHrzt / piCount) / (M_PI * piCount)) / M_PI);
    zPercentage = m_moveAngleHrzt / (M_PI/2);
    */

    //float angle = dt * (M_PI/translateMultiplier);
    //cout << m_moveAngleHrzt << endl;
    //cout << radius << endl;
    //cout << xzRadius << endl;
    //cout << "x%: " << xPercentage << ", " << "z%: " << zPercentage << endl;

    if (m_velocity.x < 0)
    {
      //moving left
      m_moveAngleHrzt -= dt * (M_PI/translateMultiplier) / m_moveSpeed;
      m_position.x = xzRadius * sin(m_moveAngleHrzt);
      m_position.z = xzRadius * cos(m_moveAngleHrzt);
      //cout << m_moveAngleHrzt << endl;

      //cout << "(X:" << m_position.x << ",Z: " << m_position.z << ")" << endl;
    }
    else if (m_velocity.x > 0)
    {
      //moving right
      m_moveAngleHrzt += dt * (M_PI/translateMultiplier) / m_moveSpeed;
      m_position.x = xzRadius * sin(m_moveAngleHrzt);
      m_position.z = xzRadius * cos(m_moveAngleHrzt);
      //cout << m_moveAngleHrzt << endl;

      //cout << "(X:" << m_position.x << ",Z: " << m_position.z << ")" << endl;
    }

    if (m_velocity.y < 0)
    {
      //moving down
      if (m_position.y > m_maxHeight * -1)
      {
        m_position.y += m_velocity.y;
      }
    }
    else if (m_velocity.y > 0)
    {
      //moving up
      if (m_position.y < m_maxHeight)
      {
        m_position.y += m_velocity.y;
      }
    }

    /*
    else if (m_velocity.y < 0)
    {
      //tilting down
      m_moveAngleVert -= dt * (M_PI/translateMultiplier) / m_moveSpeed;
      //cout << m_moveAngleVert << endl;

      

      m_position.x = radius * sin(m_moveAngleVert) * 0;
      m_position.y = radius * cos(m_moveAngleVert);
      m_position.z = radius * sin(m_moveAngleVert);

      cout << sin(m_moveAngleVert) << endl;

      //cout << "(X: " << m_position.x << ",Y:" << m_position.y << ",Z: " << m_position.z << ")" << endl;
    }
    */

    //cout << "(X: " << m_position.x << ",Y:" << m_position.y << ",Z: " << m_position.z << ")" << endl;

    /*
    if (m_velocity.x < 0)
    {
      //moving left
      //cout << "moving left" << endl;
      m_moveAngleHrzt += dt * (M_PI/translateMultiplier) / m_moveSpeed;
      m_position = glm::vec3(radius * sin(m_moveAngleHrzt), 
                             m_position.y, 
                             radius * cos(m_moveAngleHrzt));
      //cout << "Horizontal: " << m_moveAngleHrzt << endl;
    }
    else if (m_velocity.x > 0)
    {
      //moving right
      //cout << "moving right" << endl;
      m_moveAngleHrzt -= dt * (M_PI/translateMultiplier) / m_moveSpeed;
      m_position = glm::vec3(radius * sin(m_moveAngleHrzt), 
                             m_position.y, 
                             radius * cos(m_moveAngleHrzt));
      //cout << "Horizontal: " << m_moveAngleHrzt << endl;
    }

    if (m_velocity.y < 0)
    {
      //moving down
      m_moveAngleVert += dt * (M_PI/translateMultiplier) / m_moveSpeed;
      m_position = glm::vec3(m_position.x,
                             radius * cos(m_moveAngleVert),
                             radius * sin(m_moveAngleVert));
      //cout << "Vertical: " << m_moveAngleVert << endl;
    }
    else if (m_velocity.y > 0)
    {
      //moving up
      m_moveAngleVert -= dt * (M_PI/translateMultiplier) / m_moveSpeed;
      m_position = glm::vec3(m_position.x,
                             radius * cos(m_moveAngleVert),
                             radius * sin(m_moveAngleVert));
      //cout << "Vertical: " << m_moveAngleVert << endl;
    }
    */
    
    //if moving forward/backward:
    //create a vector pointing from camera position to origin position
    //move along this vector
    if (m_velocity.z < 0)
    {
      m_position += glm::normalize(m_position - m_focusPoint) * m_moveSpeed;
    }
    else if (m_velocity.z > 0)
    {
      //only move if far enough away
      if (radius > 2)
      {
        m_position -= glm::normalize(m_position - m_focusPoint) * m_moveSpeed;
      }
    }
  }

  //cout << "(X: " << m_position.x << ",Y:" << m_position.y << ",Z: " << m_position.z << ")" << endl;

  //m_position += m_velocity;

  view = glm::lookAt( m_position,                 //Eye Position
                      m_focusPoint,               //Focus point
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
