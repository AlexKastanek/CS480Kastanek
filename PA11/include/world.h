#ifndef WORLD_H
#define WORLD_H

#include <sstream>
#include "graphics_headers.h"
#include "physics.h"
#include "trigger_object.h"
#include "obstacle.h"

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
  void Render(GLint &modelMatrix, unsigned int obj);
  void Reset();

  void GenerateScores(string topTenList[10], bool& highScore);

  int GetObjectCount();
  bool isGameOver();
  int GetScore();
  bool IsNewHighScore();
  string* GetTopTenStats();

  glm::mat4 m_cameraTransform;
  
private:
  int m_objectCount = 20;

  Obstacle *m_ground;
  btTriangleMesh *m_groundColMesh;

  Obstacle *m_target;
  btTriangleMesh *m_targetColMesh;

  bool m_gameOver = false;
  int m_score = 0;

  bool m_newHighScore = false;
  string m_topTenStats[10];
  ofstream m_fout;
  
};

#endif /* WORLD_H */
