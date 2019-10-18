/*
 * Program.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "./Instructions/IMov.h"
#include "./Instructions/IAdd.h"
#include "./Instructions/ISub.h"
#include "./Instructions/IInc.h"
#include "./Instructions/IDec.h"
#include "./Instructions/IJump.h"
#include "./Instructions/ICMP.h"

namespace AR {

class Machine;

class Program {
	friend class Machine;
private:
	Instructions instrs;
public:
	Program(const std::string& code = "");
	virtual ~Program();

	friend Program& operator<<(Program& p, std::shared_ptr<Instruction> i);
};

} /* namespace AR */

#endif /* PROGRAM_H_ */
