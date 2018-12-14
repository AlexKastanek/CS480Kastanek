#ifndef WORLD_H
#define WORLD_H


#include <sstream>
#include <btBulletDynamicsCommon.h>
#include <vector>
#include "graphics_headers.h"
#include "shader.h"
#include "physics.h"
#include "trigger_object.h"
#include "obstacle.h"
#include "gun.h"
#include "bullet.h"
#include "camera.h"
#include "bb.h"
#include "cross.h"
#include "can.h"
#include "target.h"
#include "sound.h"

using namespace std;
class Sound;
class World : public Physics
{
public:
  World();
  World(glm::vec3 gravity);
  ~World();

  bool Initialize();
  void Update(unsigned int dt);
  void Render();
  void Render(Shader& shader, unsigned int obj);
  void Reset();

  void GenerateScores(string topTenList[10], bool& highScore);

  int GetObjectCount();
  bool isGameOver();
  int GetScore();
  bool IsNewHighScore();
  string* GetTopTenStats();
  int GetAmmoCount();
  
  void createBullet(float, float, float, float, float);
  void setCameraPos(glm::vec3 cameraPos);

  glm::mat4 m_cameraTransform;
  
  
private:
  int m_objectCount = 20;//object count
  float m_worldScale = 3;

  //ground stuff
  Obstacle *m_ground;
  btTriangleMesh *m_groundColMesh;

  //target stuff
  Target *m_target;
  btTriangleMesh *m_targetColMesh;
  Target *m_target2;
  btTriangleMesh *m_target2ColMesh;
  Target *m_target3;
  btTriangleMesh *m_target3ColMesh;
  double m_targetHitTimer = 0.0f;
  
  //target array 1
  const int m_row1Count = 4;
  Target *m_row1[4];
  btTriangleMesh *m_row1ColMesh[4];
  
  //target array 2
  const int m_row2Count = 4;
  Target *m_row2[4];
  btTriangleMesh *m_row2ColMesh[4];
  
  //target array 3
  const int m_row3Count = 4;
  Target *m_row3[4];
  btTriangleMesh *m_row3ColMesh[4];
  
  //can
  Can *m_can;
  btTriangleMesh *m_canColMesh;
  double m_canHitTimer = 0.0f;
  bool m_canIsHit = false;
  
  //bullet stuff
  const int m_bulletInstance = 10;
  Bullet *m_bullets[10];
  int m_bulletIterator = 0;
  int m_ammoCount = 0;
  const int m_ammoMax = 20;
  
  Cross *m_cross;
  bool m_crossRender = true;

  Gun *m_gun;

  vector<BB*> m_bbContainer;
  btTriangleMesh *m_bbColMesh;

  bool m_gameOver = false;
  int m_score = 0;

  bool m_newHighScore = false;
  string m_topTenStats[10];
  ofstream m_fout;
  
};

#endif /* WORLD_H */
