/*
 * Enum.cpp
 *
 *   Created on: Oct 28, 2011
 *  Last Chance: 12:08:40 PM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#include <typeinfo>
#include "../include/Enum.h"

namespace cpputil {

Enum::Enum(int id, std::string str) {
	// TODO Auto-generated constructor stub
	this->id = id;
	this->str = str;
}

Enum::Enum(std::string str) {
	this->str = str;
	this->id = Enum::idCount++;
}

Enum::~Enum() {
	// TODO Auto-generated destructor stub
}

std::string Enum::toString() const {
	return this->str;
}

int Enum::getId() const {
	return this->id;
}

bool Enum::operator==(const Enum& obj) {
	if (typeid(*this).name() == typeid(obj).name()) {
		return this->id == obj.id;
	}
	return false;
}

Enum& Enum::operator=(const Enum& obj) {
	this->id = obj.id;
	this->str = obj.str;
	return *this;
}

int Enum::idCount = 0;

} /* namespace cpputil */
