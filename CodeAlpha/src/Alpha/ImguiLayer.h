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

	};
}