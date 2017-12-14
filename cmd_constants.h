#pragma once
#ifndef CMD_CONSTANTS
#define CMD_CONSTANTS

#include <string>

namespace CMD
{
	class Constants final
	{
	public:
		explicit Constants() = delete;

		static const std::string &CmdDesc()
		{
			static const auto localString = std::string{"test"};
			return localString;
		}

		enum class COMMANDS
		{

		};

		enum class FLAGS
		{

		};
	};
}

#endif // CMD_CONSTANTS