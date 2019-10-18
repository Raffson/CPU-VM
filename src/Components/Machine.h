/*
 * Machine.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include "Program.h"
#include <map>

namespace AR {

//Instead of using std::map, 
//the name of a 'Register' is considered a data-member
typedef std::vector<Register> memory;

class Machine {
private:
	memory mem;
	std::map<std::string, bool> flags;

public:
	Machine();
	virtual ~Machine();

	void run(const Program& p);

	Register getRegister(const std::string& n) const;
};

} /* namespace AR */

#endif /* MACHINE_H_ */
