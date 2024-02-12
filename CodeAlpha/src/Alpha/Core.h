#pragma once

#ifdef ALPHA_PLATFORM_WINDOWS
	#ifdef ALPHA_BUILD_DLL
		#define ALPHA_API __declspec(dllexport)
	#else
		#define ALPHA_API __declspec(dllimport)
	#endif
#else
	#error Alpha only supports windows!
#endif