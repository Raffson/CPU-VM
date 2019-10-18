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

class IDec: public AR::UnaryInstruction {
public:
	IDec(const std::string& code);
	virtual ~IDec();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IDEC_H_ */
