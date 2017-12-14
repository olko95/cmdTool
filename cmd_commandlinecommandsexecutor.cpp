#include "cmd_commandlinecommandsexecutor.h"

using namespace CMD;

CommandLineCommandsExecutor::CommandLineCommandsExecutor(const std::vector<std::unique_ptr<ICommand>> &commands) : m_commands{commands}
{

}

CommandLineCommandsExecutor::~CommandLineCommandsExecutor() = default;

void CommandLineCommandsExecutor::run() const
{
	for (const auto &it : m_commands)
	{
		it->execute();
	}
}

