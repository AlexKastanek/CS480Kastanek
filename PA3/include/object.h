#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    Object(glm::mat4* parent);
    ~Object();
    void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();
    glm::mat4* GetModelReference();
    bool IsPaused();
    unsigned int GetSpinDirection();
    unsigned int GetOrbitDirection();

    void SetPaused(bool paused);
    void SetSpinDirection(unsigned int spin);
    void SetOrbitDirection(unsigned int orbit);

  private:
    glm::mat4 model;
    glm::mat4* m_parent;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angleTranslate;
    float angleRotate;

    bool m_paused;
    unsigned int m_spinDirection;
    unsigned int m_orbitDirection;
};

#endif /* OBJECT_H */
