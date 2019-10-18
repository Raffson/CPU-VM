/*
 * IMov.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IMov.h"

namespace AR {

IMov::IMov(const std::string& code)
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

IMov::~IMov() {
	// TODO Auto-generated destructor stub
}

void IMov::execute(std::vector<Register>& data,
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
					j.content = i.content;
					return;
				}
			}
			throw std::runtime_error("Register '"+dest+"' does not exist!");
		}
		else
		{
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
	}
}


} /* namespace AR */
