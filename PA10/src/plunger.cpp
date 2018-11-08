#include "plunger.h"

Plunger::Plunger() : PhysicsObject()
{

}

Plunger::Plunger(string filename) : PhysicsObject(filename)
{

}

Plunger::Plunger(string filename, float scale, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f)) : PhysicsObject(filename, scale, position)
{

}

Plunger::~Plunger()
{

}

bool Plunger::Initialize()
{

}

void Plunger::Update(unsigned int dt)
{

}

void Plunger::Pull()
{

}

void Plunger::Release()
{

}