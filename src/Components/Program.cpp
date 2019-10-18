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
		unsigned int j = i+1;
		for(; j < code.size(); j++ )
		//find ';' to indicate next instruction
		{
			if( code[j] == ';' )
				break;
		}
		std::string ins = code.substr(i, 3);
		std::string val = code.substr(i+3, j-i-3);
		if( ins == "MOV" ) instrs.push_back( std::make_shared<IMov>(val) );
		else if( ins == "ADD" ) instrs.push_back( std::make_shared<IAdd>(val) );
		else if( ins == "SUB" ) instrs.push_back( std::make_shared<ISub>(val) );
		else if( ins == "INC" ) instrs.push_back( std::make_shared<IInc>(val) );
		else if( ins == "DEC" ) instrs.push_back( std::make_shared<IDec>(val) );
		else if( ins == "CMP" ) instrs.push_back( std::make_shared<ICMP>(val) );
		else if( ins == "JNE" ) instrs.push_back( std::make_shared<IJNE>(val) );
		else if( ins == "JNZ" ) instrs.push_back( std::make_shared<IJNZ>(val) );
		i = j;
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
