#include "cmd_commandlineflagssetter.h"

using namespace CMD;

CommandLineFlagsSetter::CommandLineFlagsSetter(const std::vector<std::unique_ptr<IFlag>> &flags) : m_flags{flags}
{
}

void CommandLineFlagsSetter::run() const
{
	for (const auto &it : m_flags)
	{
		it->setFlag();
	}
}
