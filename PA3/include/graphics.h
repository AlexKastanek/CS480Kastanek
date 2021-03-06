#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "planet.h"
#include "moon.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt);
    void Render();

    bool IsPlanetPaused();
    unsigned int GetPlanetSpin();
    unsigned int GetPlanetOrbit();
    bool IsMoonPaused();
    unsigned int GetMoonSpin();
    unsigned int GetMoonOrbit();

    void SetPlanetPaused(bool paused);
    void SetPlanetSpin(unsigned int spin);
    void SetPlanetOrbit(unsigned int orbit);
    void SetMoonPaused(bool paused);
    void SetMoonSpin(unsigned int spin);
    void SetMoonOrbit(unsigned int orbit);

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    Planet *m_planet;
    Moon *m_moon;
};

#endif /* GRAPHICS_H */
