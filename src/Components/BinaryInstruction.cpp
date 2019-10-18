/*
 * Instruction.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "BinaryInstruction.h"

namespace AR {

BinaryInstruction::BinaryInstruction(const std::string& code) {
  for( unsigned int i=0; i < code.size(); i++ )
	{
		if(code[i] == '(')
		{
			for( unsigned int j=i+1; j < code.size(); j++ )
			{
				if( code[j] == ',' )
				{
					dest = code.substr(i+1, j-i-1);
				}
			}
		}
		else if(code[i] == ',')
		{
			for( unsigned int j=i+1; j < code.size(); j++ )
			{
				if( code[j] == ')' )
				{
					src = code.substr(i+1, j-i);
					src.pop_back();
				}
			}
		}
	}
}

BinaryInstruction::~BinaryInstruction() {
	// TODO Auto-generated destructor stub
}

} /* namespace AR */
