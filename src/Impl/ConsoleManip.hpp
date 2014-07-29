/* code by plusb preco */

#ifndef PRECO_CONSOLE_MANIP_HPP
#define PRECO_CONSOLE_MANIP_HPP

// preDefinition
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
//#define _WIN32_WINNT 0x0500

#include "PrecoHelper/Vector2.hpp"
#include <windows.h>

namespace preco
{
	class String;

	class ConsoleManip final
	{
	public :

		// 커서타입 enum
		enum class CursorType
		{
			NoCursor,
			SolidCursor,
			NormalCursor
		};

		// 소멸자 삭제
		~ConsoleManip() = delete;
	
		// 화면 초기화
		static void clearScreen();
	
		// 커서 위치 가져오기
		static Vector2i getCursorPosition();
	
		// 커서 위치 설정
		static void setCursorPosition(const Vector2i& position);
	
		// 커서 타입 설정
		static void setCursorType(CursorType cursorType);
	
		// milliSeconds동안 멈추기
		static void sleepFor(unsigned int milliSeconds);
	
		// 콘솔창 크기 설정하기
		static void setConsoleSize(const Vector2i& size);
	
		// 콘솔창 제목 설정하기
		static void setConsoleTitle(const String& title);
	};

} // namespace preco

#endif // PRECO_CONSOLE_MANIP_HPP