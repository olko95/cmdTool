#pragma once
#ifndef CMD_COMMANDLINEFLAGSFACTORY
#define CMD_COMMANDLINEFLAGSFACTORY

#include "cmd_iflag.h"

#include <string>
#include <memory>

namespace CMD
{
	class CommandLineFlagsFactory final
	{
	public:
		explicit CommandLineFlagsFactory();
		~CommandLineFlagsFactory();

		CommandLineFlagsFactory(const CommandLineFlagsFactory &) = delete;
		CommandLineFlagsFactory(CommandLineFlagsFactory &&) = delete;
		CommandLineFlagsFactory &operator=(const CommandLineFlagsFactory &) = delete;
		CommandLineFlagsFactory &operator=(CommandLineFlagsFactory &&) = delete;

		std::unique_ptr<IFlag> createInstance(std::string command);

		bool isFlag(std::string flag) const;
	};
}

#endif // CMD_COMMANDLINEFLAGSFACTORY