/*
 * ISub.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef ISUB_H_
#define ISUB_H_

#include "../BinaryInstruction.h"

namespace AR {

/**
 *  \brief Class for the SUB instruction.
 */
class ISub: public AR::BinaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	ISub(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~ISub();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};
} /* namespace AR */

#endif /* ISUB_H_ */
