/*
	questa classe gestisce tutte le possibili azioni
	che si possono svolgere all'interno del database
*/

#ifndef LEGAMI_H
#define LEGAMI_H

#include "User.h"
#include "Contatto.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Legami
{
	public:
		// inizio leggendo il database senza nessuna sessione aperta (nessun utente puntato)
		Legami(vector<User*>* =0, User* =0);

		void leggi(vector<string>*);
		string scrivi() const;

		// gestione utenti
		bool registra(User*);
		bool cancella(User*);

		User** trovaUser(string) const;

		bool login(string, string);
		void logout();
		void cambiaRuolo(User*, string);

		vector<Gruppo*>* elencoGruppi() const;

		vector<User*>* find(Profilo*, int =0) const;

	private:
		// il database
		vector<User*>* database;
		// collegamento allo user che ha eseguito il login
		User* user;
};

#endif

