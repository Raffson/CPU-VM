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
	Register A("AAAAAAA");
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

void Machine::run(const Program& p)
{
	//unsigned int iptr = mem.back().content;
	for(unsigned int iptr = 0; iptr < p.instrs.size(); iptr++ )
	{
		mem.back().content = iptr;
		//std::cout << "IP = " << iptr << std::endl;
		if( iptr >= p.instrs.size() )
			throw std::runtime_error("Segmentation fault! (IP out of range)");

		p.instrs[iptr]->execute(mem, p.instrs, flags["equal"], flags["zero"]);
		iptr = mem.back().content;
		// for(unsigned int i=0; i < mem.size(); i++){
		// 	std::cout << "\t" << mem[i].name << " -> " << mem[i].content << std::endl;
		// }
	}
}

Register Machine::getRegister(const std::string& n) const
{
	for( auto& i : mem )
	{
		if( i.name == n ) return i;
	}
	throw std::runtime_error("Register '"+n+"' does not exist!");
}

} /* namespace AR */
