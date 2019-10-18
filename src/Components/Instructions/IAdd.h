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

class IAdd: public AR::BinaryInstruction {
public:
	IAdd(const std::string& code);
	virtual ~IAdd();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IADD_H_ */
