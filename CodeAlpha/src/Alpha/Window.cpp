#include "Alphapch.h"
#include "Window.h"
#include "Windows/WindowsWindow.h"
namespace Alpha
{
	std::unique_ptr<Window> Window::Create(const WindowProps& props)
	{
		#ifdef ALPHA_PLATFORM_WINDOWS
			return std::make_unique<WindowsWindow>(props);
		#else
			return nullptr;
		#endif
	}
}