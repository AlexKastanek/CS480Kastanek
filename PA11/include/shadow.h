#ifndef SHADOW_H
#define SHADOW_H

#include "graphics_headers.h"
#include "shader.h"
#include <iostream>

using namespace std;

class Shadow
{
public:

  Shadow();
  ~Shadow();

  void Initialize();
  void Update();
  void Bind(Shader& shader);
  void Reset();

  void SetLightProjection(glm::mat4 lightProjection);
  void SetLightView(glm::mat4 lightView);

private:
  const unsigned int m_shadowWidth = 1024;
  const unsigned int m_shadowHeight = 1024;

  unsigned int m_depthMapFBO; //the frame buffer
  unsigned int m_depthMap;    //the texture

  glm::mat4 m_lightProjection;
  glm::mat4 m_lightView;

};

#endif /* SHADOW_H */