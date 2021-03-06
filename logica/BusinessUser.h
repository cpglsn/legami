// Alessandro Capogna 574320
/*
	questa classe è l'evoluzione della classe User, che
	consente ad ogni BusinessUser di fare ricerche con
	un massimo di 300 risultati per ogni ricerca
*/

#ifndef BUSINESSUSER_H
#define BUSINESSUSER_H

#include "User.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Legami;
class Profilo;

class BusinessUser : public User
{
	public:
		BusinessUser(User);
		virtual ~BusinessUser();

		virtual string getRuolo() const;

		virtual vector<User*>* find(Profilo*) const;

	private:
		static const unsigned int risultatiMax;
};

#endif

