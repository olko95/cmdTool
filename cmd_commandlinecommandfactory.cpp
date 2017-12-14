#include "cmd_commandlinecommandfactory.h"

#include "cmd_icommand.h"
#include "cmd_printcommand.h"
#include "cmd_squarecommand.h"

#include "boost\program_options\variables_map.hpp"

using namespace CMD;

CommandLineCommandFactory::CommandLineCommandFactory() = default;

CommandLineCommandFactory::~CommandLineCommandFactory() = default;


std::unique_ptr<ICommand> CommandLineCommandFactory::createCommand(std::string command, const boost::program_options::variable_value &param)
{
	if (command == "print")
	{
		return std::make_unique<PrintCommand>(param.as<std::string>());
	}
	else if (command == "sqr")
	{
		return std::make_unique<SquareCommand>(param.as<int>());
	}

	return std::unique_ptr<ICommand>();
}

bool CommandLineCommandFactory::isCommand(std::string command) const
{
	if (command == "print" || command == "sqr")
		return true;

	return false;
}
