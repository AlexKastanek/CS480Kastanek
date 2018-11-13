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
    Bumper(string filename, float scale, glm::vec3 position, btTriangleMesh *triMesh, bool isBouncy);
    ~Bumper();

    bool Initialize(btTriangleMesh *triMesh);

    void Update(unsigned int dt);

private:
    
    bool m_isBouncy;

};


#endif //BULLETTUTORIAL_BUMPER_H
