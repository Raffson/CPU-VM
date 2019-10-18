/*
 * Instruction.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef UNARYINSTRUCTION_H_
#define UNARYINSTRUCTION_H_

#include "Instruction.h"


namespace AR {

class UnaryInstruction : public AR::Instruction {
protected:
	std::string dest;
public:
	UnaryInstruction(const std::string& code);
	virtual ~UnaryInstruction();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const = 0;
};

} /* namespace AR */

#endif /* UNARYINSTRUCTION_H_ */
