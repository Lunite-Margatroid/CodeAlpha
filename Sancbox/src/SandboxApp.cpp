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
		Alpha::Log::GetCoreLogger()->info("SandboxApp Running.");
		ALPHA_CLIENT_ERROR("SandboxApp Running");
		while (true);
	};
};

Alpha::Application* Alpha::CreateApplaction()
{
	return new SandboxApp();
}