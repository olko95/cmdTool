#include "cmd_commandlineflagsfactory.h"

using namespace CMD;

CommandLineFlagsFactory::CommandLineFlagsFactory() = default;

CommandLineFlagsFactory::~CommandLineFlagsFactory() = default;

std::unique_ptr<IFlag> CMD::CommandLineFlagsFactory::createInstance(std::string command)
{
	return std::unique_ptr<IFlag>();
}

bool CommandLineFlagsFactory::isFlag(std::string flag) const
{
	return true;
}
