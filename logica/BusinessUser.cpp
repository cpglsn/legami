#include "BusinessUser.h"


const int unsigned BusinessAccount::max_risultati = 10;


BusinessUser::BusinessUser( Legami* l, string n, string pass, Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g)
	: User( l, n, pass, p, c, g) { User::ruolo("business");}


BusinessUser::~BusinessUser() {}


vector<User*>* BusinessAccount::find(Profilo* p) const
{
	vector<User*>* match = gestore->find(p);

	// rimuovo l'user corrente dalla lista
	for(unsigned int i=0; i<match->size(); ++i)
	{
		if( *(*match)[i] == *this )
		match->erase(match->begin() + i);
	}

	if( match->size() > risultatiMax ) // cancella i risultati in piu'
		match->erase( match->begin() + risultatiMax, match->end() );

	return match;
}

