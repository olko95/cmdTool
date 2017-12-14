#pragma once
#ifndef PRINTCOMMAND
#define PRINTCOMMAND

#include "cmd_icommand.h"

#include <string>

namespace CMD
{
	class PrintCommand final: public ICommand
	{

	public:
		explicit PrintCommand(const std::string message);
		virtual ~PrintCommand();

		PrintCommand(const PrintCommand &) = delete;
		PrintCommand(PrintCommand &&) = delete;
		PrintCommand &operator=(const PrintCommand &) = delete;
		PrintCommand &operator=(PrintCommand &&) = delete;

	private:
		virtual void execute() override;
		virtual std::string getDescritpion() override;

	private:
		const std::string m_message;
	};
}

#endif // PRINTCOMMAND