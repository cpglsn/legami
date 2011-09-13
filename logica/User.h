/*
	questa classe gestisce il login (nick e pass) insieme alla
	lista dei contatti dello user e alla lista dei gruppi cui
	appartiene, oltre al ruolo che lo user ha (base, business o
	executive)
*/

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Contatto.h"

using std::string;
using std::vector;

class Profilo;
class Gruppo;
class Contatto;
class Legami;

class User
{
	friend class Legami;

	private:
		// nick prende il posto di username e identifica univocamente ogni user
		string nick, password;

		Legami* gestore;

	protected:
		Profilo* profilo;
		// insieme dei contatti di User
		vector<Contatto*>* collegamenti;
		// l'insieme dei gruppi dello User
		vector<Gruppo*>* gruppi;
		// ruolo dell'utente (base, business, executive)
		string ruolo;

	public:
		User(string, string, Profilo* =0, vector<Contatto*>* =0, vector<Gruppo*>* =0);
		virtual ~User();

		bool operator==(const User&);

		string getNick() const;
		string getRuolo() const;

		// gestione collegamenti aggiungi Contatto senza negoziazione (come Twitter)
		bool insertContatto(Contatto*);
		bool eraseContatto(Contatto*);

		void setGestore(Legami*);

		// trova i profili con le caratteristiche del profilo cercato
		virtual vector<User*>* find(Profilo*) const;
};

#endif

