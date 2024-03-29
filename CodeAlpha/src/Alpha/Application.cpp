#include "Alphapch.h"
#include "Application.h"
#include "Event/ApplicationEvent.h"
namespace Alpha
{
	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		ALPHA_CORE_ASSERT(!s_Application, "App Instance Should exist single");
		Application::s_Application = this;

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
		float currentTime = glfwGetTime();
		float lastTime;
		float deltaTime;

		while (m_Running)
		{
			lastTime = currentTime;
			currentTime = glfwGetTime();
			deltaTime = currentTime - lastTime;

			// window OnUpdate包含消息分发
			// 每一个消息都会发送给Application::OnEvent
			m_Window->OnUpdate();
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(deltaTime);
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);
		eventDispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		for (auto it = m_LayerStack.rbegin();
			it != m_LayerStack.rend(); it++)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}


		//ALPHA_CORE_TRACE("{0}", e.ToString());
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlayer(Layer* layer)
	{
		m_LayerStack.PushOverlayer(layer);
		layer->OnAttach();
	}
}