/*
 * IInc.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IInc.h"

namespace AR {

IInc::IInc(const std::string& code) : UnaryInstruction(code)
{
	// Nothing else should be done
}

IInc::~IInc() {
	// TODO Auto-generated destructor stub
}

void IInc::execute(std::vector<Register>& data,
		const Instructions& ins,
		bool& equal, bool& zero) const
{
	equal = false;
	zero = false;
	for( auto& i : data )
	{
		if( i.name == dest )
		{
			++i.content;
			if( i.content == 0 ) zero = true;
			return;
		}
	}
	throw std::runtime_error("Register '"+dest+"' does not exist!");
}


} /* namespace AR */
