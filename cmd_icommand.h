#pragma once
#ifndef CMD_ICOMMAND
#define CMD_ICOMMAND

#include <string>

namespace CMD
{
	class ICommand
	{

	public:
		virtual ~ICommand() = default;

		virtual void execute() = 0;

		virtual std::string getDescritpion() = 0;
	};
}
#endif // CMD_ICOMMAND

