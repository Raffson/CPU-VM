/*
 * Machine.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "Machine.h"

namespace AR {

Machine::Machine()
{
	Register A("A");
	Register B("B");
	Register C("C");
	Register D("D");
	Register IP("IP");
	mem.push_back(A);
	mem.push_back(B);
	mem.push_back(C);
	mem.push_back(D);
	mem.push_back(IP);
	flags.insert( std::pair<std::string, bool>("equal", false) );
	flags.insert( std::pair<std::string, bool>("zero", false) );
}

Machine::~Machine() { }

/**
 *	\brief A little helper function that checks if the instruction pointer
 *		is out of bounds.
 */
void iptr_checker(unsigned int iptr, unsigned int nr_instr){
	if( iptr >= nr_instr )
		throw std::runtime_error("Segmentation fault! (IP out of range)");
}

void Machine::run(const Program& p)
{
	//unsigned int iptr = mem.back().content;
	for(unsigned int iptr = 0; iptr < p.instrs.size(); iptr++ )
	{
		mem.back().content = iptr;
		//std::cout << "IP = " << iptr << std::endl;
		iptr_checker(iptr, p.instrs.size());
		p.instrs[iptr]->execute(mem, flags["equal"], flags["zero"]);
		iptr = mem.back().content;
		iptr_checker(iptr, p.instrs.size());
		// the line above is not really necessary,
		// but just to be sure the jump instructions don't screw us
		// in fact, they can't because the for-loop will end,
		// but we want to stop if a jump is invalid...

		// for(unsigned int i=0; i < mem.size(); i++){
		// 	std::cout << "\t" << mem[i].name << " -> " << mem[i].content << std::endl;
		// }
	}
}

const Register& Machine::getRegister(const std::string& n) const
{
	for( auto& i : mem )
	{
		if( i.name == n ) return i;
	}
	throw std::runtime_error("Register '"+n+"' does not exist!");
}

} /* namespace AR */
