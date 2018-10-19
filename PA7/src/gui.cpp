#include "gui.h"

GUI::GUI()
{
  
}

GUI::~GUI()
{
  ImGui::DestroyContext();
}

bool GUI::Initialize(SDL_Window* window, SDL_GLContext context)
{
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

 	ImGui_ImplSDL2_InitForOpenGL(window, context);
 	ImGui_ImplOpenGL3_Init("#version 330");

 	return true;
}

void GUI::Update(SDL_Window* window, Graphics* graphics)
{
//     //bool buttonPressed = false;
// 
//   	ImGui_ImplOpenGL3_NewFrame();
//   	ImGui_ImplSDL2_NewFrame(window);
//   	ImGui::NewFrame();
// 
//     if (ImGui::Begin("Menu", NULL, ImGuiWindowFlags_NoResize));
//     {
//       if (ImGui::Button("Play/Pause Planet"))
//       {
//         if (graphics->IsPlanetPaused())
//         {
//           graphics->SetPlanetPaused(0);
//         }
//         else
//         {
//           graphics->SetPlanetPaused(1);
//         }
//       }
//       if (ImGui::Button("Change Orbit Direction"))
//       {
//         if (graphics->GetPlanetOrbit() == 0)
//         {
//           graphics->SetPlanetOrbit(1);
//         }
//         else
//         {
//           graphics->SetPlanetOrbit(0);
//         }
//       }
//       if (ImGui::Button("Change Spin Direction"))
//       {
//         if (graphics->GetPlanetSpin() == 0)
//         {
//           graphics->SetPlanetSpin(1);
//         }
//         else
//         {
//           graphics->SetPlanetSpin(0);
//         }
//       }
// 
//       ImGui::Separator();
// 
//       ImGui::Text("Info");
// 
//       if (graphics->IsPlanetPaused())
//       {
//         ImGui::Text("Paused");
//       }
//       else
//       {
//         ImGui::Text("Playing");
//       }
// 
//       if (graphics->GetPlanetOrbit() == 0)
//       {
//         ImGui::Text("Planet Orbit Direction: Clockwise");
//       }
//       else
//       {
//         ImGui::Text("Planet Orbit Direction: Counter-Clockwise");
//       }
// 
//       if (graphics->GetPlanetSpin() == 0)
//       {
//         ImGui::Text("Planet Spin Direction: Clockwise");
//       }
//       else
//       {
//         ImGui::Text("Planet Spin Direction: Counter-Clockwise");
//       }
// 
//     }
//     ImGui::End();
//     

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplSDL2_NewFrame(window);
  ImGui::NewFrame();

  if (ImGui::Begin("HUD", NULL))
  {
    string textMode, textSimSpeed;
    string *textObjectName = new string();

    //set text for mode and object name
    textMode = "Camera Mode: ";
    *textObjectName = "Name: ";
    switch(graphics->GetCameraMode())
    {
      case 0:
        textMode += "Focus";
        switch (graphics->GetFocusedObject())
        {
          case 0:
            *textObjectName += "The Sun";
            break;
          case 1:
            *textObjectName += "Mercury";
            break;
          case 2:
            *textObjectName += "Venus";
            break;
          case 3:
            *textObjectName += "Earth";
            break;
          case 4:
            *textObjectName += "Mars";
            break;
          case 5:
            *textObjectName += "Jupiter";
            break;
          case 6:
            *textObjectName += "Saturn";
            break;
          case 7:
            *textObjectName += "Uranus";
            break;
          case 8:
            *textObjectName += "Neptune";
            break;
          case 9:
            *textObjectName += "Pluto";
            break;
          default: 
            break;
        }
        break;
      case 1:
        textMode += "Free";
        break;
      case 2:
        textMode += "Overview";
        break;
      default:
        break;
    }

    //set text for simulation speed
    sprintf(&textSimSpeed[0], "Simulation Speed: %d", graphics->GetSimulationSpeed());

    //display text
    ImGui::Text(textMode.c_str());
    ImGui::Text(textSimSpeed.c_str());
    if (graphics->GetCameraMode() == MODE_FOCUS)
    {
      ImGui::Separator();
      ImGui::Text(textObjectName->c_str());
    }

    delete textObjectName;
  }
  ImGui::End();

}

void GUI::Render(SDL_Window* window, SDL_GLContext context)
{
  ImGui::Render();
  //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  ImGuiIO& io = ImGui::GetIO(); (void)io;
  SDL_GL_MakeCurrent(window, context);
  glViewport(0,0,(int)io.DisplaySize.x, (int)io.DisplaySize.y);
  //glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}