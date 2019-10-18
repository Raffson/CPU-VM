/*
 * Instruction.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef BINARYINSTRUCTION_H_
#define BINARYINSTRUCTION_H_

#include "Instruction.h"

namespace AR {

class BinaryInstruction : public AR::Instruction {
protected:
	std::string dest;
	std::string src;
public:
	BinaryInstruction(const std::string& code);
	virtual ~BinaryInstruction();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const = 0;
};

} /* namespace AR */

#endif /* BINARYINSTRUCTION_H_ */
