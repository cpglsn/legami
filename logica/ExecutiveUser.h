/*
	questa classe è l'evoluzione della classe BusinessUser
	che consente ad ogni BusinessUser di fare ricerche con
	un massimo di 700 risultati per ogni ricerca
*/

#ifndef EXECUTIVEUSER_H
#define EXECUTIVEUSER_H

#include "BusinessUser.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Legami;
class Profilo;

class ExecutiveUser : public BusinessUser
{
	public:
		ExecutiveUser(BusinessUser);
		virtual ~ExecutiveUser();

		virtual string getRuolo() const;

		virtual vector<User*>* find(Profilo*) const;

	private:
		static const unsigned int risultatiMax;
};

#endif

