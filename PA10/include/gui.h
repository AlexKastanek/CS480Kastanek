#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <stdio.h>
using namespace std;

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "graphics_headers.h"
#include "window.h"
#include "graphics.h"

class GUI
{
public:
  
	GUI();
	~GUI();

	int Initialize(SDL_Window* window, SDL_GLContext context);
	void Update(SDL_Window* window, Graphics* graphics, int ballCounter);
	void Render(SDL_Window* window, SDL_GLContext context);

private:
	
};

#endif /* GUI_H */