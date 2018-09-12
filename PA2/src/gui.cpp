#include "gui.h"

GUI::GUI()
{

}

GUI::~GUI()
{

}

bool GUI::Initialize(SDL_Window* window, SDL_GLContext context)
{
	cout << "initializing imgui stuff" << endl;

	m_window = window;
  	ImGui::CreateContext();
  	ImGuiIO& io = ImGui::GetIO(); (void)io;
  	//io = ImGui::GetIO(); (void)io;
  	ImGui_ImplSDL2_InitForOpenGL(window, context);
  	ImGui_ImplOpenGL3_Init("#version 130");

  	//ImGui_ImplOpenGL3_NewFrame();
  	//ImGui_ImplSDL2_NewFrame(gWindow);
  	//ImGui::NewFrame();

  	//ImGui::BeginMenuBar();
  	//{
  	//}
  	//ImGui::EndMenuBar();

  	cout << "ending init imgui stuff" << endl;

  	return true;
}

void GUI::Update()
{
	//cout << "starting new frame" << endl;
  	//ImGui_ImplOpenGL3_Init("#version 130");
  	ImGui_ImplOpenGL3_NewFrame();
  	ImGui_ImplSDL2_NewFrame(m_window);
  	ImGui::NewFrame();

  	ImGui::Begin("Test");
  	if (ImGui::BeginMenuBar())
  	{
  		cout << "displaying menu bar" << endl;
  		ImGui::EndMenuBar();
  	}
  	ImGui::End();
}

void GUI::Render()
{
	ImGui::Render();
}