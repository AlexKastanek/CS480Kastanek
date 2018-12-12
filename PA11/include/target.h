#ifndef Target_H
#define Target_H

#include "physics_object.h"

using namespace std;

class Target : public PhysicsObject
{
public:
  Target();
  Target(string filename);
  Target(string filename, float scale, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
  Target(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh);
  ~Target();

  bool Initialize();
  void Update(unsigned int dt);

private:
    
    float m_translateMod;
    glm::mat4 translation;
    bool m_direction = true;

};

#endif /* Target_H */
