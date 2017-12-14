#pragma once
#ifndef SQUARECOMMAND
#define SQUARECOMMAND

#include "cmd_icommand.h"

#include <string>

namespace CMD
{
	class SquareCommand final : public ICommand
	{

	public:
		explicit SquareCommand(int value);
		virtual ~SquareCommand();

		SquareCommand(const SquareCommand &) = delete;
		SquareCommand(SquareCommand &&) = delete;
		SquareCommand &operator=(const SquareCommand &) = delete;
		SquareCommand &operator=(SquareCommand &&) = delete;

	private:
		virtual void execute() override;
		virtual std::string getDescritpion() override;

	private:
		const int m_value;
	};
}

#endif // SQUARECOMMAND