#ifndef WORLD_H
#define WORLD_H

#include "graphics_headers.h"
#include "physics.h"
#include "board.h"
#include "ball.h"
#include "lane.h"
#include "flipper_left.h"
#include "flipper_right.h"
#include "plunger.h"
#include "cylinder.h"
#include "launch_barrier.h"
#include "trigger_object.h"

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
  FlipperRight& GetFlipperRight();
  FlipperLeft& GetFlipperLeft();
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
  btTriangleMesh *boardMesh;  
  btTriangleMesh *rightFlipperMesh;
  btTriangleMesh *leftFlipperMesh;

  Ball *m_ball;
  Lane *m_laneRight;
  Lane *m_laneLeft;
  btTriangleMesh *rightLaneMesh;
  btTriangleMesh *leftLaneMesh;
  FlipperRight *m_flipperRight;
  FlipperLeft *m_flipperLeft;
  Plunger *m_plunger;

  Cylinder *m_cylinder;
  btTriangleMesh *cylMesh;

  LaunchBarrier *m_launchBarrier;
  TriggerObject *m_launchArea;

  /*
  float m_boardSpecular;
  float m_ballSpecular;
  float m_flipperRightSpecular;
  float m_flipperLeftSpecular;
  float m_cylinderSpecular;
  */

  bool m_ballInLaunchRange = true;
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
