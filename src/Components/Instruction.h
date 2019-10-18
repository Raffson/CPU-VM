/*
 * Instruction.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "Register.h"
#include <vector>
#include <typeinfo>
#include <memory>
#include <iostream>
#include <exception>
#include <string>


namespace AR {

class Instruction; // forward declaration for typedef
typedef std::vector<std::shared_ptr<Instruction> > Instructions;

/**
 *  \brief Abstract Base Class for an instruction.
 */
class Instruction {
public:
	/**
	 *  \brief Default constructor.
	 */
	Instruction();

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Instruction();

	/**
	 *  \brief Pure virtual function that should be implemented
	 *		by derived classes.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const = 0;
};

} /* namespace AR */

#endif /* INSTRUCTION_H_ */
