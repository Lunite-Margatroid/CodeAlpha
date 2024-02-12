#pragma once
#include "Application.h"

#ifdef ALPHA_PLATFORM_WINDOWS

extern Alpha::Application* Alpha::CreateApplaction();

int main(int argc, char** argv)
{
	auto app = Alpha::CreateApplaction();
	app->Run();
	delete app;
	return 0;
}
#endif