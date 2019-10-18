/*
 * Instruction.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "Register.h"
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>

namespace AR {

class Instruction; // forward declaration for typedef
typedef std::vector<std::shared_ptr<Instruction>> Instructions;

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
        bool& equal, bool& zero) const = 0;
};

} /* namespace AR */

#endif /* INSTRUCTION_H_ */
