#ifndef WORLD_H
#define WORLD_H

#include "graphics_headers.h"
#include "physics.h"
#include "board.h"

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

  Board& GetBoard();

private:

  Board *m_board;
};

#endif /* WORLD_H */