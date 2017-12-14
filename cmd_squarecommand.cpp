#include "cmd_squarecommand.h"

#include <iostream>

using namespace CMD;
using namespace std;

SquareCommand::SquareCommand(int value) : m_value{value}
{
}

SquareCommand::~SquareCommand() = default;

void SquareCommand::execute()
{
	std::cout << m_value * m_value << std::endl;
}

std::string CMD::SquareCommand::getDescritpion()
{
	return std::string("squares value");
}
