#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include <btBulletDynamicsCommon.h>
#include "object.h"

using namespace std;

class PhysicsObject : public Object
{
public:
  PhysicsObject();
  PhysicsObject(string filename);
  PhysicsObject(string filename, float scale);
  ~PhysicsObject();

  void Update(unsigned int dt);

private:
  btCollisionShape *m_collider;
  btRigidBody *m_rigidBody;
};

#endif