#include "light.h"

Light::Light()
{
  position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
  direction = glm::vec3(0.0f, 0.0f, 1.0f);

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