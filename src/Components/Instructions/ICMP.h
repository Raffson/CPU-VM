/*
 * ICMP.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef ICMP_H_
#define ICMP_H_

#include "../BinaryInstruction.h"

namespace AR {

/**
 *  \brief Class for the CMP (compare) instruction.
 */
class ICMP: public AR::BinaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	ICMP(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~ICMP();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* ICMP_H_ */
