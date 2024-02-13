#pragma once
#include "Application.h"
#include "Log.h"

#ifdef ALPHA_PLATFORM_WINDOWS

extern Alpha::Application* Alpha::CreateApplaction();

int main(int argc, char** argv)
{
	Alpha::Log::Init();

	auto app = Alpha::CreateApplaction();
	app->Run();
	delete app;
	return 0;
}
#endif