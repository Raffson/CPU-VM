/*
 * main.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

 /*! \mainpage Exam for Advanced Programming at University of Antwerp
 *
 * \section intro_sec Introduction
 *
 * The goal was to make a virtual machine that can execute the following instructions:
 * \li 1) ADD (addition), currently not supporting immediate values
 * \li 2) SUB (subtraction), currently not supporting immediate values
 * \li 3) CMP (compare), currently not supporting immediate values
 * \li 4) DEC (decrement by 1)
 * \li 5) INC (increment by 1)
 * \li 6) JNE (jump not equal)
 * \li 7) JNZ (jump not zero)
 * \li 8) MOV (move/load immediate)
 *
 * \section install_sec Installation
 *
 * All you need is a C++ compiler that supports the c++11 standard
 * together with CMake 2.6
 *
 * Installation :
 * \li 1) Open up terminal & navigate to this folder (i.e. "/WhateverPathYouChose/CPU-VM")
 * \li 2) Make a new directory, usually named "build" (i.e. "mkdir build")
 * \li 3) Make another directory called "bin" (i.e. "mkdir bin")
 * \li 4) Change to the build directory (i.e. "cd <name-of-build-folder>")
 * \li 5) Type "cmake .." followed by "make install"
 * \li 6) Switch to the bin folder & run the program (i.e. "cd ../bin" followed by "./CPU-VM")
 *	remark : the program MUST be ran from the 'bin' folder,
 *		otherwise problems are caused with the font
 *
 * Uninstall procedure :
 * \li 1) Open up terminal & navigate to this folder (i.e. "/WhateverPathYouChose/CPU-VM")
 * \li 2) Remove <name-of-build-folder> which was created upon installation
 * \li 3) Remove the executable in the 'bin' folder & leave default.tff intact.
 *
 */

#include "./Components/Machine.h"
#include "./Components/Program.h"

#include <fstream>
#include <sstream>

/**
 *  \file main.cpp
 *  \brief Everything starts in this file.
 *
 *  This file will be responsible for directing all components for RM.
 */


/**
 *  \namespace AR
 *  \brief A namespace to bundle the work.
 *
 */
using namespace AR;

/**
 *  \fn main
 *  \brief The entry point of the program.
 */
int main(int argc, char* argv[])
{
	try {
		int n = 10;
		if( argc > 1){
			try{
				n = atoi(argv[1]);
			}
			catch(std::exception& e){
				n = 10;
			}
		}
		//Program prog("MOV(D,"+std::to_string(n-1)+");MOV(A,0);MOV(B,1);MOV(C,B);ADD(B,A);MOV(A,C);DEC(D);JNZ(3);");
		Program prog;
		prog << std::make_shared<IMov>("(D,"+std::to_string(n-1)+")");
		prog << std::make_shared<IMov>("(A,0)");
		prog << std::make_shared<IMov>("(B,1)");

		prog << std::make_shared<IMov>("(C,B)");
		prog << std::make_shared<IAdd>("(B,A)");
		prog << std::make_shared<IMov>("(A,C)");

		prog << std::make_shared<IDec>("(D)");
		prog << std::make_shared<IJNZ>("(3)");

		Machine m;
		m.run(prog);

		std::cout << "F_" << n << " = " << m.getRegister("B").getContent()
				<< std::endl;

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Fatal error encountered: " << e.what() << std::endl;
	}
	return 0;
}
