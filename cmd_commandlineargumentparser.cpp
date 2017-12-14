#include "cmd_commandlineargumentparser.h"

#include "cmd_icommand.h"
#include "cmd_iflag.h"

#include <boost/program_options.hpp>
#include <iostream>

using namespace CMD;
using namespace boost::program_options;


CommandLineArgumentParser::CommandLineArgumentParser(int argc, char *argv[]) : m_argc{ argc }, m_argv{argv}
{
	m_commandFactory = std::make_unique<CommandLineCommandFactory>();
	m_flagsFactory	 = std::make_unique<CommandLineFlagsFactory>();
}

void CommandLineArgumentParser::parse()
{
	options_description desc{ "Options" };
	desc.add_options()
			("help,h", "Help screen")
			("print,p", value<std::string>(), "Print")
			("sqr,s", value<int>(), "Square")
			("l", "Lights")
			("m", "Messages");

	command_line_parser parser{ m_argc, m_argv };
	parser.options(desc).allow_unregistered().style(command_line_style::default_style | command_line_style::allow_slash_for_short);
	parsed_options parsed_options = parser.run();

	variables_map vm;
	store(parsed_options, vm);
	notify(vm);

	for (const auto &it : vm)
	{
		if (m_commandFactory->isCommand(it.first))
		{
			auto command = m_commandFactory->createCommand(it.first, it.second);
			m_commands.push_back(std::move(command));
		}
		else if (m_flagsFactory->isFlag(it.first))
		{
			auto flag = m_flagsFactory->createInstance(it.first);
			m_flags.push_back(std::move(flag));
		}
	}

	m_isParsed = true;
}


const std::vector<std::unique_ptr<ICommand>> &CommandLineArgumentParser::getCommands() 
{
	if (!m_isParsed)
		parse();

	return m_commands;
}

const std::vector<std::unique_ptr<IFlag>> &CommandLineArgumentParser::getFlags() 
{
	if (!m_isParsed)
		parse();

	return m_flags;
}
