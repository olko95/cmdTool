#pragma once
#ifndef CMD_COMMANDLINEARGUMENTPARSER
#define CMD_COMMANDLINEARGUMENTPARSER

#include <vector>
#include <memory>

#include "cmd_commandlineflagsfactory.h"
#include "cmd_commandlinecommandfactory.h"

namespace CMD
{
	class ICommand;
	class IFlag;

	class CommandLineArgumentParser final
	{
	public:
		explicit CommandLineArgumentParser(int argc, char *argv[]);

		CommandLineArgumentParser(const CommandLineArgumentParser &) = delete;
		CommandLineArgumentParser(CommandLineArgumentParser &&) = delete;
		CommandLineArgumentParser &operator=(const CommandLineArgumentParser &) = delete;
		CommandLineArgumentParser &operator=(CommandLineArgumentParser &&) = delete;

		const std::vector<std::unique_ptr<ICommand>> &getCommands();
		const std::vector<std::unique_ptr<IFlag>> &getFlags();

	private:
		void parse();

	private:
		std::unique_ptr<CommandLineCommandFactory> m_commandFactory{ nullptr };
		std::unique_ptr<CommandLineFlagsFactory> m_flagsFactory{ nullptr };

	private:
		bool m_isParsed{ false };

		char **m_argv{nullptr};
		int   m_argc{0};

		std::vector<std::unique_ptr<ICommand>> m_commands;
		std::vector<std::unique_ptr<IFlag>>    m_flags;
	};
}

#endif // CMD_COMMANDLINEARGUMENTPARSER