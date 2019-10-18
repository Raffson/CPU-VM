/*
 * IJump.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef IJUMP_H_
#define IJUMP_H_

#include "../UnaryInstruction.h"

namespace AR {

class IJNE: public AR::UnaryInstruction {
public:
	IJNE(const std::string& code);
	virtual ~IJNE();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

class IJNZ: public AR::UnaryInstruction {
public:
	IJNZ(const std::string& code);
	virtual ~IJNZ();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IJUMP_H_ */
