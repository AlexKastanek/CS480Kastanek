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
  void rowUpdate(unsigned int dt);
  void popUpdate(unsigned int dt, glm::vec3 pos);
  
  void setSpeed(float);
 
  TriggerObject *m_trigger;
  bool m_isUp = true;

private:
    
    glm::mat4 translation;
    char m_direction;
    
    float m_speedMod;

};

#endif /* Target_H */
