#ifndef OBJECT_H
#define OBJECT_H
#include "model.h"
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "graphics_headers.h"

//includes for Assimp
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/color4.h>

using namespace std;

class Object
{
    struct Material
    {
        string name;
        glm::vec3 color;
    };

  public:
    Object();
    Object(string filename);
    ~Object();
    virtual void Update(unsigned int dt);
    void Render();
    
    /*
    bool LoadObject(string in_filename, 
                    vector<Vertex>* out_vertices, 
                    vector<unsigned int>* out_indices);
    bool LoadMaterial(string in_filename,
                      vector<Material>* out_materials);
    */

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
    //Model* m;

  protected:
    Object* m_parent;
    vector<Object*> m_children;

    Model* m_renderData;

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
