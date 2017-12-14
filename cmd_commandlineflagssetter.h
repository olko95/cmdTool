#pragma once
#ifndef CMD_COMMANDLINEFLAGSSETTER
#define CMD_COMMANDLINEFLAGSSETTER

#include "cmd_iflag.h"

#include <vector>
#include <memory>

namespace CMD
{	
	class CommandLineFlagsSetter final
	{
	public:
		explicit CommandLineFlagsSetter(const std::vector<std::unique_ptr<IFlag>> &flags);

		CommandLineFlagsSetter(const CommandLineFlagsSetter &) = delete;
		CommandLineFlagsSetter(CommandLineFlagsSetter &&) = delete;
		CommandLineFlagsSetter &operator=(const CommandLineFlagsSetter &) = delete;
		CommandLineFlagsSetter &operator=(CommandLineFlagsSetter &&) = delete;

		void run() const;

	private:
		bool									   m_finished{ false };
		const std::vector<std::unique_ptr<IFlag>> &m_flags;
	};
}

#endif // CMD_COMMANDLINEARGUMENTPARSER