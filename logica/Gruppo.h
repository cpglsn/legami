#ifndef GRUPPO_H
#define GRUPPO_H

#include <vector>
#include <string>
#include "User.h"

using std::string;
using std::vector;

class User;

class Gruppo
{
	private:
		string nome, descrizione;
		vector<User*>* membri;

	public:
		Gruppo( string, string, vector<User*>*);
		virtual ~Gruppo();

		string getNome() const;
		string getDescrizione() const;
		vector<User*>* getMembri() const;

		bool appartiene( User*) const;
		void aggiungi( User*);
		void cancella( User*);

		bool operator==(const Gruppo&);
};

#endif

