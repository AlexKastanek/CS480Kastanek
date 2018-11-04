#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "graphics_headers.h"
//#include "physics.h"
#include "world.h"
#include "camera.h"
#include "shader.h"
//#include "object.h"
//#include "board.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();

    bool Initialize(int width, int height);
    void Update(unsigned int dt);
    void Render();

    void moveFlipper(char input);

    World *m_world;
    
    void increaseBrightness();
    void decreaseBrightness();
    
    Shader *m_shader;

  private:
    std::string ErrorString(GLenum error);

    //Physics *m_physics;
    
    Camera *m_camera;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix; 
    
    float ambientMod = .5;
};

#endif /* GRAPHICS_H */
