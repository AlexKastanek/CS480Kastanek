#ifndef LIGHT_H
#define LIGHT_H

#include "graphics_headers.h"
#include "shadow.h"
#include <iostream>

using namespace std;

class Light
{
public:

  Light();
  ~Light();

  /* public attributes to be sent to shader */

  glm::vec4 position;
  glm::vec3 direction;

  glm::vec4 ambient;
  glm::vec4 diffuse;
  glm::vec4 specular;

  float shininess;

  bool directional;
  float angle;
  float attenuation;

  bool castsShadows;
  

private:

};

#endif /* LIGHT_H */