/*
 * IAdd.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IADD_H_
#define IADD_H_

#include "../Instruction.h"

namespace AR {

class IAdd: public AR::Instruction {
private:
	std::string dest;
	std::string src;
public:
	IAdd(const std::string& code);
	virtual ~IAdd();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IADD_H_ */
