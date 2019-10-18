/*
 * IMov.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IMov.h"

namespace AR {

IMov::IMov(const std::string& code) : BinaryInstruction(code)
{
	// Nothing else should be done
}

IMov::~IMov() {
	// TODO Auto-generated destructor stub
}

void IMov::execute(std::vector<Register>& data,
		bool& equal, bool& zero) const
{
	equal = false;
	zero = false;
	for( auto& i : data )
	{
		if( i.name == src )
		{
			for( auto& j : data )
			{
				if( j.name == dest )
				{
					j.content = i.content;
					return;
				}
			}
			throw std::runtime_error("Register '"+dest+"' does not exist!");
		}
	}
	int d = 0;
	try
	{
		d = atoi( src.c_str() );
	}
	catch(...)
	{
		throw std::runtime_error("Invalid immediate value : "+src+"");
	}

	for( auto& j : data )
	{
		if( j.name == dest )
		{
			j.content = d;
			return;
		}
	}
	throw std::runtime_error("Register '"+dest+"' does not exist!");
}


} /* namespace AR */
