#include "BusinessUser.h"
#include "Legami.h"

// numero massimo di risultati della ricerca per utenti business
const int unsigned BusinessUser::risultatiMax = 10;


BusinessUser::BusinessUser(string n, string pass, Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g)
	: User(n, pass, User::Buisness, p, c, g)
{

}


BusinessUser::~BusinessUser()
{

}

