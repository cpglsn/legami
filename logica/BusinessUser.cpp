#include "BusinessUser.h"


// numero massimo di risultati della ricerca per utenti business
const int unsigned BusinessUser::risultatiMax=300;


BusinessUser::BusinessUser(string n, string pass)
	: User(n, pass)
{

}


BusinessUser::~BusinessUser() {}

