#ifndef WORLD_H
#define WORLD_H

#include "graphics_headers.h"
#include "physics.h"
#include "board.h"
#include "ball.h"

using namespace std;

class World : public Physics
{
public:
  World();
  World(glm::vec3 gravity);
  ~World();

  bool Initialize();
  void Update(unsigned int dt);
  void Render(GLint &modelMatrix);

  Board& GetBoard();
  Ball& GetBall();

private:
  Board *m_board;
  Ball *m_ball;

};

#endif /* WORLD_H */