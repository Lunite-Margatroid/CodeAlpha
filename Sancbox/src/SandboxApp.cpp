#include <Alpha.h>

class ExampleLayer :public Alpha::Layer
{
public:
	ExampleLayer() {}
	~ExampleLayer() {}
	void OnUpdate(float ts) override
	{
		ALPHA_CLIENT_TRACE("Example Update");
	}
};

class SandboxApp :public Alpha::Application
{
public:
	SandboxApp()
	{
		m_LayerStack.PushLayer(new ExampleLayer());
	}
	~SandboxApp()
	{}
};

Alpha::Application* Alpha::CreateApplaction()
{
	return new SandboxApp();
}