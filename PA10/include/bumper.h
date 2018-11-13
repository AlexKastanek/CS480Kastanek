#ifndef BULLETTUTORIAL_BUMPER_H
#define BULLETTUTORIAL_BUMPER_H
#include "physics_object.h"

using namespace std;

class Bumper : public PhysicsObject
{
public:
    Bumper();
    Bumper(string filename);
    Bumper(string filename, float scale, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
    Bumper(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh, float initAngle);
    ~Bumper();

    bool Initialize(btTriangleMesh *triMesh);

    void Update(unsigned int dt);

private:
    
    glm::vec3 m_pivotPosition;
    float m_initialAngle;
    float m_currentAngle;

};


#endif //BULLETTUTORIAL_BUMPER_H
