#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Windows/WindowsWindow.h"
#include "Event/ApplicationEvent.h"

namespace Alpha
{

	class ALPHA_API Application
	{
	protected:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	public:
		Application();
		virtual ~Application();

		virtual void Run();
		virtual void OnEvent(Event& e);
		virtual bool OnWindowClose(WindowCloseEvent& e);
		
	};

	Application* CreateApplaction();

}