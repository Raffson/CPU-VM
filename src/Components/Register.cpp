/*
 * Register.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Raffson
 */

#include "Register.h"

namespace AR {

Register::Register(const std::string& n, const byte& c)
    : name(n)
    , content(c)
{
}

Register::~Register() {}

const byte& Register::getContent() const
{
    return content;
}

} /* namespace AR */
