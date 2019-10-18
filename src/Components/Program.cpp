/*
 * Program.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "Program.h"

namespace AR {

Program::Program(const std::string& code)
{
	for( unsigned int i = 0; i < code.size(); i++ )
	{
		//search for next instruction
		if( code[i] == ';' )
		{
			unsigned int j = i+1;
			for(; j < code.size(); j++ )
			//find ';' to indicate next instruction
			{
				if( code[j] == ';' )
					break;
			}
			std::string c = code.substr(i, j);
			if( c == "MOV" ) instrs.push_back( std::make_shared<IMov>(c) );
			else if( c == "ADD" ) instrs.push_back( std::make_shared<IAdd>(c) );
			else if( c == "SUB" ) instrs.push_back( std::make_shared<ISub>(c) );
			else if( c == "INC" ) instrs.push_back( std::make_shared<IInc>(c) );
			else if( c == "DEC" ) instrs.push_back( std::make_shared<IDec>(c) );
			else if( c == "CMP" ) instrs.push_back( std::make_shared<ICMP>(c) );
			else if( c == "JNE" ) instrs.push_back( std::make_shared<IJNE>(c) );
			else if( c == "JNZ" ) instrs.push_back( std::make_shared<IJNZ>(c) );
		}
	}
}

Program& operator<<(Program& p, std::shared_ptr<Instruction> i)
{
	p.instrs.push_back(i);
	return p;
}

Program::~Program() {
	// TODO Auto-generated destructor stub
}

} /* namespace AR */
