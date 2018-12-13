#ifndef Target_H
#define Target_H

#include "physics_object.h"
#include "trigger_object.h"


using namespace std;

class Target : public PhysicsObject
{
public:
  Target();
  Target(string filename);
  Target(string filename, float scale, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
  Target(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh, char dir);
  ~Target();

  bool Initialize();
  void Update(unsigned int dt);
  
  TriggerObject *m_trigger;

private:
    
    float m_translateMod;
    glm::mat4 translation;
    char m_direction;
    
    

};

#endif /* Target_H */
