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

#define BIT(x) 1 << x

#define ALPHA_ASSERT_ENABLE 1

#if ALPHA_ASSERT_ENABLE
	#define ALPHA_CLIENT_ASSERT(x, ...)				{if(!x) {ALPHA_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__);}}
	#define ALPHA_CORE_ASSERT(x, ...)				{if(!x) {ALPHA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);}}
#else
	#define ALPHA_CLIENT_ASSERT(x, ...)	
	#define ALPHA_CORE_ASSERT(x, ...)	
#endif