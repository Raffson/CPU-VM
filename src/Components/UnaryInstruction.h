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

/**
 *  \brief Abstact class for unary instructions.
 */
class UnaryInstruction : public AR::Instruction {
protected:
	/**
	 *  \brief Represents the destination register.
	 */
	std::string dest;

public:
	/**
	 *  \brief Custom constructor to be used for all derived classes.
	 */
	UnaryInstruction(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~UnaryInstruction();

	/**
	 *  \brief Still a pure virtual function to be implemented
	 *		by derived classes.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const = 0;
};

} /* namespace AR */

#endif /* UNARYINSTRUCTION_H_ */
