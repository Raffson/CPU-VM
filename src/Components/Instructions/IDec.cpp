/*
 * IDec.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IDec.h"

namespace AR {

IDec::IDec(const std::string& code)
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

IDec::~IDec() {
	// TODO Auto-generated destructor stub
}

void IDec::execute(std::vector<Register>& data,
		const Instructions& ins,
		bool& equal, bool& zero) const
{
	equal = false;
	zero = false;
	for( auto& i : data )
	{
		if( i.name == dest )
		{
			--i.content;
			if( i.content == 0 ) zero = true;
			return;
		}
	}
	throw std::runtime_error("Register '"+dest+"' does not exist!");
}


} /* namespace AR */
