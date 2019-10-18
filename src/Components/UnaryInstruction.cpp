/*
 * Instruction.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "UnaryInstruction.h"

namespace AR {

UnaryInstruction::UnaryInstruction(const std::string& code)
{
    for (unsigned int i = 0; i < code.size(); i++) {
        if (code[i] == '(') {
            for (unsigned int j = i + 1; j < code.size(); j++) {
                if (code[j] == ')') {
                    dest = code.substr(i + 1);
                    dest.pop_back();
                }
            }
        }
    }
}

UnaryInstruction::~UnaryInstruction()
{
    // TODO Auto-generated destructor stub
}

} /* namespace AR */
