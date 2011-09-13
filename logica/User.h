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
		string nick, password; // nick prende il posto di username e identifica univocamente ogni user

	protected:
		Profilo* profilo;
		vector<Contatto*>* collegamenti; // insieme dei contatti di User
		vector<Gruppo*>* gruppi; // l'insieme dei gruppi dello User
		string ruolo; // ruolo dell'utente (base, business, executive)

	public:
		User( string, string, Profilo* =0, vector<Contatto*>* =0, vector<Gruppo*>* =0);
		virtual ~User();

		string getRuolo() const;

		bool operator==(const User&);
		string getNick() const;

		// gestione collegamenti aggiungi Contatto senza negoziazione (come Twitter)
		bool insertContatto(Contatto*);
		bool eraseContatto(Contatto*);
};

#endif

