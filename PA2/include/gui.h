#ifndef GUI_H
#define GUI_H

#include <iostream>
using namespace std;

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "window.h"

class GUI
{
public:
	GUI();
	~GUI();
	bool Initialize(SDL_Window* window, SDL_GLContext context);
	void Update();
	void Render();

private:
	SDL_Window* m_window;
	//ImGuiIO& io;
};

#endif /* GUI_H */