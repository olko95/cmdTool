#include "cmd_printcommand.h"

#include <iostream>

using namespace CMD;
using namespace std;

PrintCommand::PrintCommand(const std::string message) : m_message{message}
{
}

PrintCommand::~PrintCommand() = default;

void PrintCommand::execute()
{
	std::cout << m_message << endl;
}

std::string PrintCommand::getDescritpion()
{
	return std::string("prints message");
}
