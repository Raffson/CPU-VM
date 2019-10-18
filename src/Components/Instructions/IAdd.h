/*
 * IAdd.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IADD_H_
#define IADD_H_

#include "../BinaryInstruction.h"

namespace AR {

/**
 *  \brief Class for the ADD instruction.
 */
class IAdd: public AR::BinaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	IAdd(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~IAdd();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IADD_H_ */
