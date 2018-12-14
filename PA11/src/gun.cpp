#include "gun.h"

Gun::Gun(string filename, float scale, glm::vec3 position) : Object(filename, scale, position)
{

}

Gun::~Gun()
{
  delete m_renderData;
  m_children.clear();
}

void Gun::Update(unsigned int dt)
{
  model = glm::translate(
    m_cameraTransform, 
    glm::vec3(
      1.0f,
      -1.0f,
      -2.0f));
}

void Gun::SetCameraTransform(glm::mat4 transform)
{
  m_cameraTransform = transform;
}