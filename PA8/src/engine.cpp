#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_gui;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

int Engine:: getHeight(){
    return m_WINDOW_HEIGHT;
}

int Engine:: getWidth(){
    return m_WINDOW_WIDTH;
}

bool Engine::Initialize()
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Start the GUI
  m_gui = new GUI();
  if (!m_gui->Initialize(m_window->GetWindow(), m_window->GetContext()))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();


    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();
    
    while(SDL_PollEvent(&m_event) != 0)
    {
      if (!ImGui::IsMouseHoveringAnyWindow())
      {
        //ImGui_ImplSDL2_ProcessEvent(&m_event)
        Keyboard();
      }
    }

    // Update and render the GUI
    //m_gui->Update(m_window->GetWindow(), m_graphics);
    //m_gui->Render(m_window->GetWindow(), m_window->GetContext());

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else
  {
  	switch (m_event.type)
  	{
  		case SDL_KEYDOWN:
  			switch (m_event.key.keysym.sym)
  			{
  				case SDLK_ESCAPE:
  					m_running = false;
  					break;
          case SDLK_w:
            m_graphics -> moveFlipper('w');
            break;
          case SDLK_s:
            m_graphics -> moveFlipper('s');
            break;
          case SDLK_a:
            m_graphics -> moveFlipper('a');
            break;
          case SDLK_d:
            m_graphics -> moveFlipper('d');
            break;
          case SDLK_LSHIFT:
            m_graphics->m_world->FlipLeft();
            break;
          case SDLK_RSHIFT:
            m_graphics->m_world->FlipRight();
            break;
          default:
            break;
        } 			
  		  default:
  			 break;
  	}
  }
}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}