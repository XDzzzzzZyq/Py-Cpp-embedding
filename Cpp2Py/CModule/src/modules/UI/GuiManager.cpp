#include "GuiManager.h"

GuiManager::GuiManager()
	:GuiManager(1280, 720)
{}

GuiManager::GuiManager(GLuint w, GLuint h)
	:scr_w(w), scr_h(h)
{}

GuiManager::~GuiManager()
{

}

void GuiManager::Init()
{
	glfwInit();

	window = glfwCreateWindow(scr_w, scr_h, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
	if (window == nullptr)
		return;
	glfwMakeContextCurrent(window);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::SetCurrentContext(ImGui::GetCurrentContext());

	io = &ImGui::GetIO();
	SetConfigFlag(ImGuiConfigFlags_NavEnableKeyboard);     // Enable Keyboard Controls
	SetConfigFlag(ImGuiConfigFlags_NavEnableGamepad);      // Enable Gamepad Controls
	SetConfigFlag(ImGuiConfigFlags_DockingEnable);
	SetConfigFlag(ImGuiConfigFlags_ViewportsEnable);
	SetBackendFlag(ImGuiBackendFlags_PlatformHasViewports);
	SetBackendFlag(ImGuiBackendFlags_PlatformHasViewports);

	// Setup Platform/Renderer backends
	ImGui_ImplOpenGL3_Init();
	ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
}

void GuiManager::NewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void GuiManager::Render()
{
	ImGui::ShowDemoWindow();
	ImGui::Render();

	if(io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(window);
	}


	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window);
}

void GuiManager::Terminate()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}
