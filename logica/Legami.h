/*
	questa classe gestisce tutte le possibili azioni
	che si possono svolgere all'interno del database
*/

#ifndef LEGAMI_H
#define LEGAMI_H

#include "User.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Legami
{
	public:
		Legami(vector<User*>*, User*);

		// gestione utenti
		bool registra(User*);
		bool login(string, string);
		void logout();
		bool cambiaRuolo(User*);

		vector<User*>* find(Profilo*) const;

	private:
		// il database
		vector<User*>* database;
		User* user;
};

#endif

