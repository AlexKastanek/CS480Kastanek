#ifndef SHADOW_H
#define SHADOW_H

#include "graphics_headers.h"
#include <iostream>

using namespace std;

class Shadow
{
public:

  Shadow();
  ~Shadow();

  void Initialize();
  void Update();
  void Render();

private:
  const unsigned int m_shadowWidth = 1024;
  const unsigned int m_shadowHeight = 1024;

  unsigned int m_depthMapFBO; //the frame buffer
  unsigned int m_depthMap;    //the texture

};

#endif /* SHADOW_H */