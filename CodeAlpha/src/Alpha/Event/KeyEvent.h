#pragma once
#include "Event.h"

namespace Alpha
{
	class KeyEvent : public Event
	{
	protected:
		uint16_t m_KeyCode;
		KeyEvent(const uint16_t keycode) :
			m_KeyCode(keycode) {}
	public:
		uint16_t GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	class KeyPressedEvent : public KeyEvent
	{
	private:
		bool m_IsRepeat;
	public:
		KeyPressedEvent(const uint16_t keycode, bool isRepeat = false) :
			KeyEvent(keycode), m_IsRepeat(isRepeat)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(repeat = " << m_IsRepeat << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const uint16_t keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const uint16_t keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};


}