#pragma once
#ifndef CMD_COMMANDLINECOMMANDFACTORY
#define CMD_COMMANDLINECOMMANDFACTORY

#include "cmd_icommand.h"

#include <string>
#include <memory>
#include <map>

#include "boost\program_options\variables_map.hpp"

namespace CMD
{
	class CommandLineCommandFactory final
	{
	public:
		explicit CommandLineCommandFactory();
		~CommandLineCommandFactory();

		CommandLineCommandFactory(const CommandLineCommandFactory &) = delete;
		CommandLineCommandFactory(CommandLineCommandFactory &&) = delete;
		CommandLineCommandFactory &operator=(const CommandLineCommandFactory &) = delete;
		CommandLineCommandFactory &operator=(CommandLineCommandFactory &&) = delete;

		std::unique_ptr<ICommand> createCommand(std::string command, const boost::program_options::variable_value &param);

		bool isCommand(std::string command) const;
	};
}

#endif // CMD_COMMANDLINECOMMANDFACTORY