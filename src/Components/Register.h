/*
 * Register.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <string>

namespace AR {

typedef int byte;

class Machine; //forward declaration
class IMov; //forward declaration
class IAdd; //forward declaration
class ISub; //forward declaration
class IInc; //forward declaration
class IDec; //forward declaration
class ICMP; //forward declaration
class IJNE; //forward declaration
class IJNZ; //forward declaration

/**
 *  \class Register
 *  \brief Will represent Register for the BrainFuckVM.
 */
class Register {
	friend class Machine; //friend so it can manipulate the content.
	friend class IMov; //friend so it can manipulate the content.
	friend class IAdd; //friend so it can manipulate the content.
	friend class ISub; //friend so it can manipulate the content.
	friend class IInc; //friend so it can manipulate the content.
	friend class IDec; //friend so it can manipulate the content.
	friend class ICMP; //friend so it can manipulate the content.
	friend class IJNE; //friend so it can manipulate the content.
	friend class IJNZ; //friend so it can manipulate the content.

private:

	/**
	 *  \brief Will represent the Register's name.
	 */
	std::string name;

	/**
	 *  \brief Will represent the Register.
	 */
	byte content;
public:

	/**
	 *  \brief Custom constructor.
	 *  \param n The name to be used.
	 *  \param c The value to be initialized.
	 */
	Register(const std::string& n, const byte& c = 0);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Register();

	const byte& getContent() const;
};

} /* namespace AR */

#endif /* REGISTER_H_ */
