#include "ConsoleManip.hpp"
#include "PrecoHelper/String.hpp"
#include <cstdlib>
#include <chrono>
#include <thread>

namespace preco
{
	void ConsoleManip::clearScreen()
	{
		std::system("cls");
	}

	Vector2i ConsoleManip::getCursorPosition()
	{
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&bufferInfo);
	
		return {bufferInfo.dwCursorPosition.X, bufferInfo.dwCursorPosition.Y};
	}

	void ConsoleManip::setCursorPosition(const Vector2i& position)
	{
		COORD cursorPosition;
	
		cursorPosition.X = position.x;
		cursorPosition.Y = position.y;
	
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}

	void ConsoleManip::setCursorType(CursorType cursorType)
	{
		CONSOLE_CURSOR_INFO cursorInfo{};
	
		switch (cursorType)
		{
			case CursorType::NoCursor :
			{
				cursorInfo.dwSize = 1;
				cursorInfo.bVisible = false;
			
				break;
			}
		
			case CursorType::SolidCursor :
			{
				cursorInfo.dwSize = 100;
				cursorInfo.bVisible = true;
			
				break;
			}
		
			case CursorType::NormalCursor :
			{
				cursorInfo.dwSize = 20;
				cursorInfo.bVisible = true;
			
				break;
			}
		}
	
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursorInfo);
	}

	void ConsoleManip::sleepFor(unsigned int milliSeconds)
	{
		std::chrono::milliseconds duration{milliSeconds};
	
		std::this_thread::sleep_for(duration);
	}

	void ConsoleManip::setConsoleSize(const Vector2i& size)
	{
		COORD position;
	
		position.X = size.x;
		position.Y = size.y;

		SMALL_RECT rect;
	
		rect.Top = 0;
		rect.Left = 0;
		rect.Bottom = size.y - 1;
		rect.Right = size.x - 1;

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
		SetConsoleScreenBufferSize(handle, position);
		SetConsoleWindowInfo(handle, true, &rect);
	}

	void ConsoleManip::setConsoleTitle(const String& title)
	{
		SetConsoleTitle(title.wstr().c_str());
	}

} // namespace preco