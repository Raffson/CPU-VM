/*
 * IAdd.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "IAdd.h"

namespace AR {

IAdd::IAdd(const std::string& code)
    : BinaryInstruction(code)
{
    // Nothing else should be done
}

IAdd::~IAdd()
{
    // TODO Auto-generated destructor stub
}

void IAdd::execute(std::vector<Register>& data,
    bool& equal, bool& zero) const
{
    equal = false;
    zero = false;
    for (auto& i : data) {
        if (i.name == src) {
            for (auto& j : data) {
                if (j.name == dest) {
                    j.content += i.content;
                    if (j.content == 0)
                        zero = true;
                    return;
                }
            }
            throw std::runtime_error("Register '" + dest + "' does not exist!");
        } else
            throw std::runtime_error("Register '" + src + "' does not exist!");
    }
}

} /* namespace AR */
