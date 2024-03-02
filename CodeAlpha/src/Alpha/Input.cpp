#include "Alphapch.h"
#include "Input.h"

#ifdef ALPHA_PLATFORM_WINDOWS

namespace Alpha
{
	// ªÒµ√GLFWwindow÷∏’Î
#define INPUT_GLFW_WINDOW_PTR static_cast<GLFWwindow*>(Application::GetApplication().GetWindow()->GetNativeWindow())

	bool Input::IsKeyPressed(int keycode)
	{
		auto window = INPUT_GLFW_WINDOW_PTR;
		int status = glfwGetKey(window, keycode);
		return status == GLFW_PRESS || status == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(int mousecode)
	{
		auto window = INPUT_GLFW_WINDOW_PTR;
		int status = glfwGetMouseButton(window, mousecode);
		return status == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(INPUT_GLFW_WINDOW_PTR, &xpos, &ypos);
		return std::pair<float, float>((float)xpos, (float)ypos);
	}

	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}

	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
}

#endif