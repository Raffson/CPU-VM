/*
 * IAdd.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IAdd.h"

namespace AR {

IAdd::IAdd(const std::string& code)
{
	for( unsigned int i=0; i < code.size(); i++ )
	{
		if(code[i] == '(')
		{
			for( unsigned int j=i+1; j < code.size(); j++ )
			{
				if( code[j] == ',' )
				{
					dest = code.substr(i+1, j-1);
				}
			}
		}
		else if(code[i] == ',')
		{
			for( unsigned int j=i+1; j < code.size(); j++ )
			{
				if( code[j] == ')' )
				{
					src = code.substr(i+1, j);
					src.pop_back();
				}
			}
		}
	}
}

IAdd::~IAdd() {
	// TODO Auto-generated destructor stub
}

void IAdd::execute(std::vector<Register>& data,
		const Instructions& ins,
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
					j.content += i.content;
					if(j.content == 0) zero = true;
					return;
				}
			}
			throw std::runtime_error("Register '"+dest+"' does not exist!");
		}
		else
			throw std::runtime_error("Register '"+src+"' does not exist!");
	}
}


} /* namespace AR */
