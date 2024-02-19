#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace Alpha
{
	struct ALPHA_API WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(
			const std::string& title = "Alpha Engine",
			uint32_t width = 1600, 
			uint32_t height = 900 )
			: Title(title), Width(width), Height(height)
		{ }
	};

	class ALPHA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;
		virtual void OnUpdate() = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
	};
}