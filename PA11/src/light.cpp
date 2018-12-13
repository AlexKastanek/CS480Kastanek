#include "light.h"

Light::Light()
{
  position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
  focusPoint = glm::vec3(0.0f, 0.0f, 1.0f);

  ambient = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);
  diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
  specular = glm::vec4(3.0f, 3.0f, 3.0f, 3.0f);

  shininess = 50;

  directional = true;
  angle = 20.0f;
  attenuation = 0.000001f;

  castsShadows = false;
}

Light::~Light()
{

}

void Light::Initialize()
{

  //m_projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.01f, 100.0f);
  m_projection = glm::perspective(glm::radians(20.0f), 1.0f, 0.01f, 100.0f);
  
  m_view = glm::lookAt(
    glm::vec3(
      position.x,
      position.y,
      position.z),
    focusPoint, 
    glm::vec3(1.0f, 0.0f, 0.0f));

  if (castsShadows)
  {
    m_shadowMap.Initialize();
  }
}

void Light::Bind(Shader& shader)
{
  if (castsShadows)
  {
    cout << "light position: "
         << position.x << ", "
         << position.y << ", "
         << position.z << endl;
    m_shadowMap.SetLightProjection(m_projection);
    m_shadowMap.SetLightView(m_view);
    m_shadowMap.Bind(shader);
  }
}

void Light::Reset()
{
  if (castsShadows)
  {
    m_shadowMap.Reset();
  }
}

glm::mat4 Light::GetProjection()
{
  return m_projection;
}

glm::mat4 Light::GetView()
{
  return m_view;
}

Shadow& Light::GetShadow()
{
  return m_shadowMap;
}