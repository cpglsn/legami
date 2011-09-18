// Alessandro Capogna 574320
#include "BusinessUser.h"
#include "Legami.h"



// numero massimo di risultati della ricerca per utenti business
const int unsigned BusinessUser::risultatiMax=300;



BusinessUser::BusinessUser(User u)
	: User(u)
{

}



BusinessUser::~BusinessUser() {}




string BusinessUser::getRuolo() const
{
	return "business";
}



vector<User*>* BusinessUser::find(Profilo* p) const
{
	if(!gestore || !p)
		return 0;

	// manda il profilo di ricerca al gestore che ritorna sempre un vector<User*>*
	return gestore->find(p, risultatiMax);
}

