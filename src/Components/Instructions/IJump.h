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

/**
 *  \brief Class for the JNE (jump not equal) instruction.
 */
class IJNE: public AR::UnaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	IJNE(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~IJNE();

	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};


/**
 *  \brief Class for the JNZ (jump not zero) instruction.
 */
class IJNZ: public AR::UnaryInstruction {
public:
	/**
	 *  \brief Custom constructor that only calls it's superclass' constructor.
	 */
	IJNZ(const std::string& code);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~IJNZ();

	/**
	 *  \brief Implements the execution of this instruction.
	 */
	virtual void execute(std::vector<Register>& data,
			const Instructions& ins,
			bool& equal, bool& zero) const;
};

} /* namespace AR */

#endif /* IJUMP_H_ */
