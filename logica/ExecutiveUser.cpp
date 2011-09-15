#include "ExecutiveUser.h"


// numero massimo di risultati della ricerca per utenti business
const int unsigned ExecutiveUser::risultatiMax=700;


ExecutiveUser::ExecutiveUser(string n, string pass)
	: BusinessUser(n, pass)
{

}

ExecutiveUser::~ExecutiveUser() {}

