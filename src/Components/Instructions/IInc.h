/*
 * IInc.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IINC_H_
#define IINC_H_

#include "../UnaryInstruction.h"

namespace AR {

/**
 *  \brief Class for the INC (increment) instruction.
 */
class IInc: public AR::UnaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	IInc(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~IInc();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IINC_H_ */
