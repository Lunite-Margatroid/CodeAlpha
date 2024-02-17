#include "Alphapch.h"
#include "Window.h"

namespace Alpha
{
	std::unique_ptr<Window> Window::Create(const WindowProps& props)
	{
		return std::unique_ptr<Window>();
	}
}