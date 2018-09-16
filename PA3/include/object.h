#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

using namespace std;

class Object
{
  public:
    Object();
    //Object(glm::mat4* parent);
    ~Object();
    virtual void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();
    //glm::mat4* GetModelReference();
    glm::mat4 GetTranslation();
    glm::mat4 GetRotation();
    glm::mat4 GetScale();

    //void SetParent(glm::mat4* parent);
    void SetParent(Object* parent);
    void AddChild(Object* child);
    void RemoveChild();

    bool IsPaused();
    unsigned int GetSpinDirection();
    unsigned int GetOrbitDirection();

    void SetPaused(bool paused);
    void SetSpinDirection(unsigned int spin);
    void SetOrbitDirection(unsigned int orbit);

  private:
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

  protected:
    Object* m_parent;
    vector<Object*> m_children;

    glm::mat4 model;
    //glm::mat4* m_parent;
    glm::mat4 translation;
    glm::mat4 rotation;
    glm::mat4 scale;

    //TODO: move these values to planet and moon implementations and their 
    //      respective get/set functions
    float angleTranslate;
    float angleRotate;
    bool m_paused;
    unsigned int m_spinDirection;
    unsigned int m_orbitDirection;
};

#endif /* OBJECT_H */
