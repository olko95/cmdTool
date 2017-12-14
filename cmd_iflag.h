#pragma once
#ifndef CMD_IFLAG
#define CMD_IFLAG

#include <string>

namespace CMD
{
	class IFlag
	{
	public:
		virtual ~IFlag() = default;

		virtual bool setFlag() = 0;

		virtual std::string getDescritpion() = 0;
	};
}

#endif // CMD_IFLAG