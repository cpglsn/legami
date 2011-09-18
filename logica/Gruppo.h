/*
	questa classe definisce i gruppi che hanno un nome, una
	descrizione e una lista di user iscritti, quando un gruppo
	è vuoto (nemmeno uno user) viene cancellato automaticamente 
*/

#ifndef GRUPPO_H
#define GRUPPO_H

#include "User.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class User;

class Gruppo
{
	public:
		Gruppo(string, string, vector<User*>*);
		virtual ~Gruppo();

		bool operator==(const Gruppo&);

		string getNome() const;
		string getDescrizione() const;
		vector<User*>* getMembri();

		// controlla se uno user appartiene al gruppo
		bool appartiene(User*) const;

		// aggiunge uno user al gruppo
		void aggiungi(User*);

		// cancella uno user dal gruppo
		void cancella(User*);

	private:
		// il nome identifica univocamente un gruppo
		string nome, descrizione;
		vector<User*>* membri;
};

#endif

