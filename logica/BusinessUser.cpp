#include "BusinessUser.h"


// numero massimo di risultati della ricerca per utenti business
const int unsigned BusinessUser::risultatiMax = 10;


BusinessUser::BusinessUser(string n, string pass, Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g)
	: User(n, pass), User::ruolo("business") {}


BusinessUser::~BusinessUser() {}


vector<User*>* BusinessUser::find(Profilo* p) const
{
	vector<User*>* match = gestore->find(p);

	// rimuovo l'user corrente dalla lista
	for(unsigned int i=0; i<match->size(); ++i)
	{
		if(*(*match)[i] == *this)
		match->erase(match->begin() + i);
	}

	if(match->size() > risultatiMax)
		// cancella i risultati in più
		match->erase(match->begin() + risultatiMax, match->end());

	return match;
}

