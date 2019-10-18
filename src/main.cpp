/*
 * main.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
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
		std::cout << "Fatal error encountered:" << std::endl << e.what() << std::endl;
	}
	return 0;
}
