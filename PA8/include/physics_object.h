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
  virtual ~PhysicsObject();

  virtual void Update(unsigned int dt);

  //btCollisionShape* GetCollider();
  //btRigidBody* GetRigidBody();

  btCollisionShape *m_collider;
  btRigidBody *m_rigidBody;

protected:
  
};

#endif /* PHYSICS_OBJECT_H */