/*
	questa classe è l'evoluzione della classe User, che
	consente ad ogni BusinessUser di fare ricerche con
	un massimo di 300 risultati per ogni ricerca
*/

#ifndef BUSINESSUSER_H
#define BUSINESSUSER_H

#include "User.h"

class Legami;
class Profilo;

class BusinessUser : public User
{
	private:
		static const unsigned int risultatiMax;

	public:
		BusinessUser(string, string, Profilo* =0, vector<Contatto*>* =0, vector<Gruppo*>* =0);
		virtual ~BusinessUser();
};

#endif

