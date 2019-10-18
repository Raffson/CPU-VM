/*
 * Machine.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include "Program.h"
#include <map>

namespace AR {

//Instead of using std::map,
//the name of a 'Register' is considered a data-member
// -> What was I thinking!?
//    a map is definitely a better data-structure
// TODO: Rework the 'memory'
typedef std::vector<Register> memory;

/**
 *  \brief Class representing the virtual machine.
 */
class Machine {
private:
	/**
	 *  \brief Represents the registers of the virtual CPU.
	 */
	memory mem;

	/**
	 *  \brief Represents the flags of the virtual CPU.
	 */
	std::map<std::string, bool> flags;

public:
	/**
	 *  \brief Default constructor.
	 */
	Machine();

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Machine();

	/**
	 *  \brief Runs a program.
	 *	\param p The program to be executed
	 */
	void run(const Program& p);

	/**
	 *  \brief Get the register with the specified name.
	 *	\param n The name of the register to return.
	 *	\return The register with the specified name.
	 */
	const Register& getRegister(const std::string& n) const;
};

} /* namespace AR */

#endif /* MACHINE_H_ */
