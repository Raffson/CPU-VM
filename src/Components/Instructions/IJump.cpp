/*
 * IJump.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IJump.h"

namespace AR {

IJNE::IJNE(const std::string& code)
{
	for( unsigned int i=0; i < code.size(); i++ )
	{
		if(code[i] == '(')
		{
			for( unsigned int j=i+1; j < code.size(); j++ )
			{
				if( code[j] == ')' )
				{
					dest = code.substr(i+1, j);
					dest.pop_back();
				}
			}
		}
	}
}

IJNE::~IJNE() {
	// TODO Auto-generated destructor stub
}

class IJNZ;

void IJNE::execute(std::vector<Register>& data,
		const Instructions& ins,
		bool& equal, bool& zero) const
{
	zero = false;
	if( !equal )
	{
		equal = false;
		unsigned int d = 0;
		try
		{
			d = atoi( dest.c_str() );
		}
		catch(...)
		{
			throw std::runtime_error("Invalid address value : "+dest);
			return;
		}
		if( d >= ins.size() )
			throw std::runtime_error("Address out of range : "+dest);
		else
		{
			data.back().content = d;
		}
	}
}


IJNZ::IJNZ(const std::string& code)
{
	for( unsigned int i=0; i < code.size(); i++ )
	{
		if(code[i] == '(')
		{
			for( unsigned int j=i+1; j < code.size(); j++ )
			{
				if( code[j] == ')' )
				{
					dest = code.substr(i+1, j);
				}
			}
		}
	}
}

IJNZ::~IJNZ() {
	// TODO Auto-generated destructor stub
}

class IJNE;

void IJNZ::execute(std::vector<Register>& data,
		const Instructions& ins,
		bool& equal, bool& zero) const
{
	equal = false;
	if( !zero )
	{
		zero = false;
		unsigned int d = 0;
		try
		{
			d = atoi( dest.c_str() );
		}
		catch(...)
		{
			throw std::runtime_error("Invalid address value : "+dest);
			return;
		}
		if( d >= ins.size() )
			throw std::runtime_error("Address out of range : "+dest);
		else
		{
			data.back().content = d;
		}
	}
}


} /* namespace AR */
