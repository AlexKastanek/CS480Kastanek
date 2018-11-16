#include "gui.h"
#include "engine.h"
#include "camera.h"
GUI::GUI()
{

}

GUI::~GUI()
{
  ImGui::DestroyContext();
}

int GUI::Initialize(SDL_Window* window, SDL_GLContext context)
{
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

 	ImGui_ImplSDL2_InitForOpenGL(window, context);
 	ImGui_ImplOpenGL3_Init("#version 330");

  SDL_GetWindowSize(window, &m_width, &m_height);
  cout << "(" << m_width << "," << m_height << ")" << endl;

  m_fontSmall = io.Fonts->AddFontFromFileTTF("../assets/nasalization-rg.ttf", 25);
  m_fontMed = io.Fonts->AddFontFromFileTTF("../assets/nasalization-rg.ttf", 50);
  m_fontBig = io.Fonts->AddFontFromFileTTF("../assets/nasalization-rg.ttf", 100);

 	return true;
}

void GUI::Update(SDL_Window* window, Graphics* graphics)
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplSDL2_NewFrame(window);
  ImGui::NewFrame();

  ImGui::SetNextWindowPos(ImVec2(0,0));
  ImGui::SetNextWindowSize(ImVec2 (m_width, m_height));
  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0,0,0,0));

  if (m_gameOver)
  {
    //bigger text first
    ImGui::PushFont(m_fontBig);

    string gameOverDisplay = "Game Over!";
    ImVec2 gameOverSize = ImGui::CalcTextSize(gameOverDisplay.c_str());
    ImVec2 gameOverCursor = CalculateCenteredPos(gameOverSize);

    if (ImGui::Begin("", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar |ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs))
    {
      ImGui::SetCursorPos(ImVec2(gameOverCursor.x, gameOverCursor.y - 200));
      ImGui::Text(gameOverDisplay.c_str());
    }
    ImGui::End();

    ImGui::PopFont();

    //then medium text
    ImGui::PushFont(m_fontMed);

    string finalScoreDisplay = "Final Score: " + to_string(graphics->m_world->GetScore());
    ImVec2 finalScoreSize = ImGui::CalcTextSize(finalScoreDisplay.c_str());
    ImVec2 finalScoreCursor = CalculateCenteredPos(finalScoreSize);

    if (ImGui::Begin("", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar |ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs))
    {
      ImGui::SetCursorPos(ImVec2(finalScoreCursor.x, finalScoreCursor.y - 150));
      ImGui::Text(finalScoreDisplay.c_str());
    }
    ImGui::End();

    ImGui::PopFont();
  }
  else
  {
    ImGui::PushFont(m_fontSmall);

    if (ImGui::Begin("", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar |ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs))
    {
      string scoreDisplay = "Score: " + to_string(graphics->m_world->GetScore());
      ImGui::SetCursorPos(ImVec2(10,0));
      ImGui::Text(scoreDisplay.c_str());

      string ballsLeftDisplay = "Balls Left: " + to_string(graphics->m_world->GetBallCounter());
      ImGui::SetCursorPos(ImVec2(10, 20));
      ImGui::Text(ballsLeftDisplay.c_str());
    }
    ImGui::End();

    ImGui::PopFont();
  }
  
  ImGui::PopStyleColor(1);
}

void GUI::Render(SDL_Window* window, SDL_GLContext context)
{
  ImGui::Render();
  //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  ImGuiIO& io = ImGui::GetIO(); (void)io;
  SDL_GL_MakeCurrent(window, context);
  glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
  //glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  //ImGui::EndFrame();
}

ImVec2 GUI::CalculateCenteredPos(ImVec2 textSize)
{
  ImVec2 centerOfWindow = ImVec2(m_width/2, m_height/2);
  cout << "CENTER OF WINDOW" << endl;
  cout << "(" << centerOfWindow.x << "," << centerOfWindow.y << ")" << endl;

  ImVec2 textSizeOffset = ImVec2(textSize.x/2, textSize.y/2);
  cout << "TEXT OFFSET" << endl;
  cout << "(" << textSizeOffset.x << "," << textSizeOffset.y << ")" << endl;

  ImVec2 centeredCursorPos = ImVec2(
    centerOfWindow.x - textSizeOffset.x,
    centerOfWindow.y - textSizeOffset.y);
  cout << "CENTERED CURSOR" << endl;
  cout << "(" << centeredCursorPos.x << "," << centeredCursorPos.y << ")" << endl;

  return centeredCursorPos;
}

void GUI::SetGameOver(bool gameOver)
{
  m_gameOver = gameOver;
}