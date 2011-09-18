/*
	questa classe gestisce il login (nick e pass) insieme alla
	lista dei contatti dello user e alla lista dei gruppi cui
	appartiene, oltre al ruolo che lo user ha (base, business o
	executive)
*/

#ifndef USER_H
#define USER_H

#include "Profilo.h"
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
	// serve alla classe Legami sia per impostare il gestore sia per Legami::find
	friend class Legami;

	public:
		User(string, string);
		virtual ~User();

		static User* leggi(string s);
		string scrivi() const;

		bool operator==(const User&);

		virtual string getRuolo() const;

		// ritorna il nick dello user
		string getNick() const;
		Profilo* getProfilo() const;

		bool checkLogin(string, string) const;

		// gestione collegamenti aggiungi Contatto senza negoziazione (come Twitter)
		bool insertContatto(Contatto*);
		bool eraseContatto(Contatto*);

		// gestione gruppi
		bool insertGruppo(Gruppo*);
		bool eraseGruppo(Gruppo*);

		virtual vector<User*>* find(Profilo*) const;

	protected:
		// nick prende il posto di username e identifica univocamente ogni user
		string nick, password;

		Legami* gestore;

		Profilo* profilo;

		vector<Contatto*>* collegamenti;

		vector<Gruppo*>* gruppi;
};

#endif

