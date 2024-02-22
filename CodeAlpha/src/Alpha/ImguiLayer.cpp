#include "Alphapch.h"
#include "ImguiLayer.h"
namespace Alpha
{

	ImguiLayer::ImguiLayer()
		:Alpha::Layer("Imgui Layer"), m_ShowDemoWindow(true)
	{

	}
	ImguiLayer::~ImguiLayer()
	{

	}
	void ImguiLayer::OnUpdate(float ts)
	{
		/*Alpha::Window& window = *Alpha::Application::GetApplication().GetWindow();
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(window.GetWidth(), window.GetHeight());
		io.DeltaTime = ts;*/

		ImGui_ImplOpenGL3_NewFrame();
		//ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow(&m_ShowDemoWindow);

		ImGui::Render();
		

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		ALPHA_CLIENT_TRACE("ImguiLayer Update");
	}

	void ImguiLayer::OnAttach()
	{
		// setup ImGui
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		int display_w, display_h;
		Alpha::Window& window = *Alpha::Application::GetApplication().GetWindow();
		display_w = window.GetWidth();
		display_h = window.GetHeight();
		io.DisplaySize = ImVec2(display_w, display_h);

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		// Setup Platform/Renderer backends
		//ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)Alpha::Application::GetApplication().GetWindow()->GetNativeWindow(), true);
		// glsl version
		const char* glsl_version = "#version 410";
		ImGui_ImplOpenGL3_Init(glsl_version);
	}

	void ImguiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		//ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}