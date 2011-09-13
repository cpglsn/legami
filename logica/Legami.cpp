#include "Legami.h"

Legami::Legami(string* nomeFile) {}


bool Legami::registra( string n, string p)
{
	// se il nick esiste gia ritorno false
	for(unsigned int i=0; i<utenti->size(); ++i)
	{
		if((*utenti)[i] == n)
			return false;
	}

	// costruisco da zero l'account e lo aggiungo al database
	if(!utenti)
		utenti = new vector<User*>;

	// costruisco un utente senza profilo, gruppi e collegamenti, li aggiungerà dopo la registrazione
	User* u=new User( n, p, 0, 0, 0);

	utenti->push_back(u);
	        
	return true;
}
