#include <iostream>

#include <conio.h>

#include "cmd_commandlineargumentparser.h"
#include "cmd_commandlinecommandsexecutor.h"
#include "cmd_commandlineflagssetter.h"

using namespace std;
using namespace CMD;

int main(int argc, char *argv[])
{
	CommandLineArgumentParser cmdParser(argc, argv);

	// set Flags
	const auto &cmdFlags = cmdParser.getFlags();
	CommandLineFlagsSetter cmdLineFlagsSetter(cmdFlags);
	cmdLineFlagsSetter.run();

	// set Commands
	const auto &cmdCommands = cmdParser.getCommands();
	CommandLineCommandsExecutor cmdLineCommandsExecutor(cmdCommands);
	cmdLineCommandsExecutor.run();

	_getch();
	return 0;
}