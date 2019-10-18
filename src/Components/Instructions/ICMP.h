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

class ICMP: public AR::BinaryInstruction {
public:
	ICMP(const std::string& code);
	virtual ~ICMP();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* ICMP_H_ */
