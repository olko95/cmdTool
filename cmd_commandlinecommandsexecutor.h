#pragma once
#ifndef CMD_COMMANDLINECOMMANDSEXECUTOR
#define CMD_COMMANDLINECOMMANDSEXECUTOR

#include "cmd_icommand.h"

#include <vector>
#include <memory>

namespace CMD
{
	class CommandLineCommandsExecutor final
	{
	public:
		explicit CommandLineCommandsExecutor(const std::vector<std::unique_ptr<ICommand>> &commands);
		~CommandLineCommandsExecutor();
		
		CommandLineCommandsExecutor(const CommandLineCommandsExecutor &) = delete;
		CommandLineCommandsExecutor(CommandLineCommandsExecutor &&) = delete;
		CommandLineCommandsExecutor &operator=(const CommandLineCommandsExecutor &) = delete;
		CommandLineCommandsExecutor &operator=(CommandLineCommandsExecutor &&) = delete;

		void run() const;

	private:
		const std::vector<std::unique_ptr<ICommand>> &m_commands;
	};
}

#endif // CMD_COMMANDLINEARGUMENTPARSER