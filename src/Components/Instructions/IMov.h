/*
 * IMov.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IMOV_H_
#define IMOV_H_

#include "../BinaryInstruction.h"

namespace AR {

/**
 *  \brief Class for the MOV (move/load immediate) instruction.
 */
class IMov: public AR::BinaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	IMov(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~IMov();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IMOV_H_ */
