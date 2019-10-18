/*
 * IMov.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IMOV_H_
#define IMOV_H_

#include "../BinaryInstruction.h"

namespace AR {

class IMov: public AR::BinaryInstruction {
public:
	IMov(const std::string& code);
	virtual ~IMov();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IMOV_H_ */
