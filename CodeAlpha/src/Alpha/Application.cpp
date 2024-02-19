#include "Alphapch.h"
#include "Application.h"
#include "Event/ApplicationEvent.h"
namespace Alpha
{

	Application::Application()
	{
		Alpha::WindowProps windowProps;
		m_Window = std::make_unique<Alpha::WindowsWindow>(windowProps);
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		printf("Alpha::Application Running.");
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);
		eventDispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		ALPHA_CORE_TRACE("{0}", e.ToString());
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}