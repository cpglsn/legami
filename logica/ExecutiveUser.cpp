// Alessandro Capogna 574320
#include "ExecutiveUser.h"
#include "Legami.h"



// numero massimo di risultati della ricerca per utenti business
const int unsigned ExecutiveUser::risultatiMax=700;



ExecutiveUser::ExecutiveUser(BusinessUser b)
	: BusinessUser(b)
{

}



ExecutiveUser::~ExecutiveUser() {}



string ExecutiveUser::getRuolo() const
{
	return "executive";
}



vector<User*>* ExecutiveUser::find(Profilo* p) const
{
	if(!gestore || !p)
		return 0;

	// manda il profilo di ricerca al gestore che ritorna sempre un vector<User*>*
	return gestore->find(p, risultatiMax);
}

