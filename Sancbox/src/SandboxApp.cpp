#include <Alpha.h>
#include <stdio.h>
class SandboxApp :public Alpha::Application
{
public:
	SandboxApp()
	{}
	~SandboxApp()
	{}

	void Run() override
	{
		Alpha::KeyPressedEvent event(0);
		ALPHA_CLIENT_INFO(event.ToString());
		ALPHA_CLIENT_ERROR("SandboxApp Running");
		while (true);
	};
};

Alpha::Application* Alpha::CreateApplaction()
{
	return new SandboxApp();
}