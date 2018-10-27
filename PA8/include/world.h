#ifndef WORLD_H
#define WORLD_H

#include "graphics_headers.h"
#include "physics.h"
#include "board.h"
#include "ball.h"
#include "flipper.h"

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
  Flipper& GetFlipperRight();

private:
  Board *m_board;
  Ball *m_ball;
  Flipper *m_flipperRight;

};

#endif /* WORLD_H */