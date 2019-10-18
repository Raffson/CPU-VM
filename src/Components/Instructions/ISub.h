/*
 * ISub.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef ISUB_H_
#define ISUB_H_

#include "../Instruction.h"

namespace AR {

class ISub: public AR::Instruction {
private:
	std::string dest;
	std::string src;
public:
	ISub(const std::string& code);
	virtual ~ISub();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};
} /* namespace AR */

#endif /* ISUB_H_ */
