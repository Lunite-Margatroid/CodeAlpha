#pragma once
#include "Core.h"
#include "GLFW/glfw3.h"
#include "Application.h"
namespace Alpha
{
	class ALPHA_API Input
	{
	public:
		static bool IsKeyPressed(int keycode);
		static bool IsMouseButtonPressed(int mousecode);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX() ;
		static float GetMouseY();
	};
}