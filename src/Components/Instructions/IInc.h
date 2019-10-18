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

class IInc: public AR::UnaryInstruction {
public:
	IInc(const std::string& code);
	virtual ~IInc();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IINC_H_ */
