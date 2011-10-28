#include <iostream>
using namespace std;


#include "../include/Enum.h"
using namespace cpputil;

class DiaSemana : public Enum {
public:
	static const DiaSemana SEGUNDA;
	static const DiaSemana TERCA;
	static const DiaSemana QUARTA;
	static const DiaSemana QUINTA;
	static const DiaSemana SEXTA;
	static const DiaSemana SABADO;
	static const DiaSemana DOMINGO;

private:
	DiaSemana(int i, string s) : Enum(i, s) {

	}
};

const DiaSemana DiaSemana::SEGUNDA(0, "segunda");
const DiaSemana DiaSemana::TERCA(1, "segunda");
const DiaSemana DiaSemana::QUARTA(2, "segunda");
const DiaSemana DiaSemana::QUINTA(3, "segunda");
const DiaSemana DiaSemana::SEXTA(4, "segunda");
const DiaSemana DiaSemana::SABADO(5, "segunda");
const DiaSemana DiaSemana::DOMINGO(6, "segunda");


int main() {
	DiaSemana domingo = DiaSemana::SEGUNDA;
	cout <<"Hoje é " << domingo.toString() << endl;
	cout << (domingo == DiaSemana::SEGUNDA) << endl;
	return 0;
}
