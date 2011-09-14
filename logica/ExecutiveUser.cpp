#include "ExecutiveUser.h"


// numero massimo di risultati della ricerca per utenti business
const int unsigned ExecutiveUser::risultatiMax = 700;


ExecutiveUser::ExecutiveUser(string n, string pass, Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g)
	: BusinessUser(n, pass, p, c, g) {}

