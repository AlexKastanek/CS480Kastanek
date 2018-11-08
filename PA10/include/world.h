#ifndef WORLD_H
#define WORLD_H

#include "graphics_headers.h"
#include "physics.h"
#include "board.h"
#include "ball.h"
#include "flipper.h"
#include "plunger.h"
#include "cylinder.h"

using namespace std;

class World : public Physics
{
public:
  World();
  World(glm::vec3 gravity);
  ~World();

  bool Initialize();
  void Update(unsigned int dt);
  void Render(GLint &modelMatrix, char obj);

  Board& GetBoard();
  Ball& GetBall();
  Flipper& GetFlipperRight();
  Flipper& GetFlipperLeft();
  Cylinder& GetCylinder();

  /*
  float GetBoardSpecular();
  float GetBallSpecular();
  float GetFlipperRightSpecular();
  float GetFlipperLeftSpecular();
  float GetCylinderSpecular();

  void SetBoardSpecular(float boardSpecular);
  void SetBallSpecular(float ballSpecular);
  void SetFlipperRightSpecular(float flipperRightSpecular);
  void SetFlipperLeftSpecular(float flipperLeftSpecular);
  void SetCylinderSpecular(float cylinderSpecular);
  */

  //flipper controls
  void moveFlipperUp();
  void moveFlipperDown();
  void moveFlipperRight();
  void moveFlipperLeft();
  void FlipRight();
  void FlipLeft();
  void PullPlunger();
  void ReleasePlunger();

  void createWalls();


private:
  Board *m_board;
  Ball *m_ball;
  Flipper *m_flipperRight;
  Flipper *m_flipperLeft;
  Plunger *m_plunger;
  Cylinder *m_cylinder;

  /*
  float m_boardSpecular;
  float m_ballSpecular;
  float m_flipperRightSpecular;
  float m_flipperLeftSpecular;
  float m_cylinderSpecular;
  */

  bool flipped = false;
  float moveForce;

  btCollisionShape *m_bottomWall;
  btCollisionShape *m_topWall;
  btCollisionShape *m_leftWall;
  btCollisionShape *m_rightWall;
  btCollisionShape *m_lid;

  btDefaultMotionState *m_bottomWallMotion;
  btDefaultMotionState *m_topWallMotion;
  btDefaultMotionState *m_leftWallMotion;
  btDefaultMotionState *m_rightWallMotion;
  btDefaultMotionState *m_lidMotion;

  btRigidBody *m_bottomWallRigid;
  btRigidBody *m_topWallRigid;
  btRigidBody *m_leftWallRigid;
  btRigidBody *m_rightWallRigid;
  btRigidBody *m_lidRigid;
};

#endif /* WORLD_H */
