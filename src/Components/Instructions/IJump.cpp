/*
 * IJump.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IJump.h"

namespace AR {

IJNE::IJNE(const std::string& code)
    : UnaryInstruction(code)
{
    // Nothing else should be done
}

IJNE::~IJNE()
{
    // TODO Auto-generated destructor stub
}

void IJNE::execute(std::vector<Register>& data,
    bool& equal, bool& zero) const
{
    zero = false;
    if (!equal) {
        equal = false;
        unsigned int d = 0;
        try {
            d = atoi(dest.c_str());
        } catch (...) {
            throw std::runtime_error("Invalid address value : " + dest);
            return;
        }
        data.back().content = d - 1;
    }
}

IJNZ::IJNZ(const std::string& code)
    : UnaryInstruction(code)
{
    // Nothing else should be done
}

IJNZ::~IJNZ()
{
    // TODO Auto-generated destructor stub
}

void IJNZ::execute(std::vector<Register>& data,
    bool& equal, bool& zero) const
{
    equal = false;
    if (!zero) {
        zero = false;
        unsigned int d = 0;
        try {
            d = atoi(dest.c_str());
        } catch (...) {
            throw std::runtime_error("Invalid address value : " + dest);
            return;
        }
        data.back().content = d - 1;
    }
}

} /* namespace AR */
