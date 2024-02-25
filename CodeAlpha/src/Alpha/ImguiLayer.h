#pragma once
#include "Layer.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "Application.h"
#include "Window.h"
namespace Alpha
{
	class ALPHA_API ImguiLayer : public Alpha::Layer
	{
	private:
		bool m_ShowDemoWindow;
	public:
		ImguiLayer();
		~ImguiLayer();
		void OnUpdate(float ts) override;

		void OnAttach() override;

		void OnDetach() override;

		void OnEvent(Event& e) override;

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		
	};
}