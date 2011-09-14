/*
	questa classe gestisce il login (nick e pass) insieme alla
	lista dei contatti dello user e alla lista dei gruppi cui
	appartiene, oltre al ruolo che lo user ha (base, business o
	executive)
*/

#ifndef USER_H
#define USER_H

#include "Contatto.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Profilo;
class Gruppo;
class Contatto;
class Legami;

class User
{
	public:
		enum Ruoli {Base,Business,Executive};

		User(string nick, string password, Profilo* =0, vector<Contatto*>* =0, vector<Gruppo*>* =0);
		virtual ~User();

		bool operator==(const User&);

		string getNick() const;
		Ruoli getRuolo() const;

		// gestione collegamenti aggiungi Contatto senza negoziazione (come Twitter)
		bool insertContatto(Contatto*);
		bool eraseContatto(Contatto*);

		void setGestore(Legami*);

	protected:
		// ruolo dell'utente (base, business, executive)
		Ruoli ruolo;

		// nick prende il posto di username e identifica univocamente ogni user
		string nick, password;

		Legami* gestore;

		Profilo* profilo;
		// insieme dei contatti di User
		vector<Contatto*>* collegamenti;
		// l'insieme dei gruppi dello User
		vector<Gruppo*>* gruppi;
};

#endif

