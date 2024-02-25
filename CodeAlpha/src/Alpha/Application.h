#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Windows/WindowsWindow.h"

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

#include "LayerStack.h"

namespace Alpha
{
	

	class ALPHA_API Application
	{
	protected:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;

		static Application* s_Application;
	public:
		Application();
		virtual ~Application();

		virtual void Run();
		virtual void OnEvent(Event& e);
		virtual bool OnWindowClose(WindowCloseEvent& e);
		
		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* layer);

		static Application& GetApplication() { return *s_Application; }

		std::unique_ptr<Window>& GetWindow() { return m_Window; }
	};

	Application* CreateApplaction();

}