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

/**
 *  \brief Abstact class for binary instructions.
 */
class BinaryInstruction : public AR::Instruction {
protected:
	/**
	 *  \brief Represents the destination register.
	 */
	std::string dest;

	/**
	 *  \brief Represents the destination register.
	 */
	std::string src;

public:
	/**
	 *  \brief Custom constructor to be used for all derived classes.
	 */
	BinaryInstruction(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~BinaryInstruction();

	/**
	 *  \brief Still a pure virtual function to be implemented
	 *		by derived classes.
	 */
	virtual void execute(std::vector<Register>& data,
			bool& equal, bool& zero) const = 0;
};

} /* namespace AR */

#endif /* BINARYINSTRUCTION_H_ */
