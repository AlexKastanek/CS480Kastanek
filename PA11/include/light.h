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

  void Initialize();

  glm::mat4 GetProjection();
  glm::mat4 GetView();

  /* public attributes to be sent to shader */

  glm::vec4 position;
  glm::vec3 focusPoint;
  //glm::vec3 direction;

  glm::vec4 ambient;
  glm::vec4 diffuse;
  glm::vec4 specular;

  float shininess;

  bool directional;
  float angle;
  float attenuation;

  bool castsShadows;
  

private:

  glm::mat4 m_projection;
  glm::mat4 m_view;

};

#endif /* LIGHT_H */