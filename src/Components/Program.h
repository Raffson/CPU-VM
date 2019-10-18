/*
 * Program.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "./Instructions/IAdd.h"
#include "./Instructions/ICMP.h"
#include "./Instructions/IDec.h"
#include "./Instructions/IInc.h"
#include "./Instructions/IJump.h"
#include "./Instructions/IMov.h"
#include "./Instructions/ISub.h"

namespace AR {

/**
 *  \brief Class representing a program.
 */
class Program {
    friend class Machine;

private:
    /**
	 *  \brief Represents the instructions.
	 */
    Instructions instrs;

public:
    /**
	 *  \brief Custom constructor allowing to pass code straight away.
	 */
    Program(const std::string& code = "");

    /**
	 *  \brief Default destructor.
	 */
    virtual ~Program();

    /**
	 *  \brief Getter for the instructions.
	 *	\return A const reference to the instructions.
	 */
    const Instructions& GetInstructions() const { return instrs; };

    /**
	 *  \brief Operator<< to insert instructions in an easy way.
	 */
    friend Program& operator<<(Program& p, std::shared_ptr<Instruction> i);
};

} /* namespace AR */

#endif /* PROGRAM_H_ */
