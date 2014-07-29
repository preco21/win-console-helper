#include "ConsoleColor.hpp"
#include <type_traits>

namespace preco
{
	void ConsoleColor::changeConsoleColor(ConsoleTextColor consoleTextColor, ConsoleBackColor consoleBackGroundColor)
	{
		using UndType = std::underlying_type<ConsoleTextColor>::type;
		using UndType2 = std::underlying_type<ConsoleBackColor>::type;
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<UndType>(consoleTextColor) | static_cast<UndType2>(consoleBackGroundColor));
	}

} // namespace preco