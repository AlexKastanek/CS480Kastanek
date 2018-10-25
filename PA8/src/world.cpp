#include "world.h"

World::World() : Physics()
{

}

World::World(glm::vec3 gravity) : Physics(gravity)
{

}

World::~World()
{

}

bool World::Initialize()
{
  m_board = new Board("..//assets//Board.obj", 13.0f);
  m_dynamicsWorld->addRigidBody(m_board->GetRigidBody());
  return true;
}

void World::Update(unsigned int dt)
{
  m_dynamicsWorld->stepSimulation(dt, 10);
  m_board->Update(dt);
}

void World::Render()
{
  m_board->Render();
}

Board& World::GetBoard()
{
  return *m_board;
}