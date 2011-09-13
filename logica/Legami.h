/*
	questa classe gestisce tutte le possibili azioni
	che si possono svolgere all'interno del database
*/

#ifndef LEGAMI_H
#define LEGAMI_H

#include <vector>
#include <string>
#include "User.h"
#include "Profilo.h"

using std::vector;
using std::string;

class Legami
{
	private:
		// il database
		vector<User*>* utenti;

	public:
		Legami(string*);

		// gestione utenti
		bool registra(const User&);
		bool login(const User&);
		bool cambiaRuolo(User*);

		// funzionalita` del gestore ad esempio, trova la lista degli User che hanno qualche caratteristica nel profilo
		vector<User*> find(Profilo*) const;
};

#endif

