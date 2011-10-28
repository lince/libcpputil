/*
 * Enum.h
 *
 *   Created on: Oct 28, 2011
 *  Last Chance: 12:08:40 PM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#ifndef ENUM_H_
#define ENUM_H_

#include <string>

namespace cpputil {

class Enum {
public:
	virtual std::string toString() const;

	virtual int getId() const;

	virtual bool operator==(const Enum& obj);

	virtual Enum& operator=(const Enum& obj);

protected:
	Enum(int id, std::string str);
	Enum(std::string str);
	virtual ~Enum();
	int id;
	std::string str;
	static int idCount;
};

} /* namespace cpputil */
#endif /* ENUM_H_ */

#define ENUM(TYPE) class TYPE : public Enum
#define ELEM(TYPE, NOME) static const TYPE NOME;
#define ELEM_VALUE
