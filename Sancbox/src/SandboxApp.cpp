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
		printf("SandboxApp Running.");
		while (true);
	};
};

Alpha::Application* Alpha::CreateApplaction()
{
	return new SandboxApp();
}