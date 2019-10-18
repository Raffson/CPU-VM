/*
 * IDec.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IDEC_H_
#define IDEC_H_

#include "../UnaryInstruction.h"

namespace AR {

/**
 *  \brief Class for the DEC (decrement) instruction.
 */
class IDec: public AR::UnaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	IDec(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~IDec();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IDEC_H_ */
