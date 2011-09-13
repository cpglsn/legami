#ifndef LEGAMI_H
#define LEGAMI_H

#include <vector>
#include <string>
#include "User.h"

using std::vector;
using std::string;

class User;
class Profilo;


class Legami
{
	private:
		vector<User*>* utenti; // il database

	public:
		Legami(string*);

		// gestione utenti
		bool registra( const User&);
		bool login(const User&);
		bool cambiaRuolo(User*);

		// funzionalita` del gestore ad esempio, trova la lista degli User che hanno qualche caratteristica nel profilo
		//vector<User*> find(Profilo*);
};

#endif

