#ifndef LEGAMI_H
#define LEGAMI_H

#include <vector>
#include <string>
#include "account.h"
#include "username.h"

using std::vector;
using std::string;

// classe di gestione 
class Legami
{
	private:
		vector<Account*>* utenti; // il database di Account
	public:
		Legami(string*);
		Account* login(Username*);
		// gestione utenti
		bool iscriviUtente(Username*);
		bool upgradeUtente(Username*);
		// funzionalita` del gestore ad esempio, trova la lista degli User che hanno qualche caratteristica nel profilo
		vector<User*> find(Profilo*);
};

#endif

