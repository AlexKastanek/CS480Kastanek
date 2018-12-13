#ifndef WORLD_H
#define WORLD_H

#include <sstream>
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

using namespace std;

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

  //ground stuff
  Obstacle *m_ground;
  btTriangleMesh *m_groundColMesh;

  //target stuff
  Obstacle *m_target;
  btTriangleMesh *m_targetColMesh;
  TriggerObject *m_targetTrigger;
  double hitTimer = 0.0f;
  
  //bullet stuff
  const int m_bulletInstance = 10;
  Bullet *m_bullets[100];
  int m_bulletIterator = 0;
  int m_ammoCount = 0;
  const int m_ammoMax = 20;
  
  Cross *m_cross;

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
