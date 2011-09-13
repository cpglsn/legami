#include "Legami.h"


Legami::Legami(string* nomeFile) {}


bool Legami::registra( const User& u)
{
	if( utenti)
	{
		// se il nick esiste gia ritorno false
		for(unsigned int i=0; i<utenti->size(); ++i)
		{
			if( *(*utenti)[i] == u );
				return false;
		}
	}

	else // costruisco da zero l'account e lo aggiungo al database
	{
		utenti = new vector<User*>;
	}

	// costruisco un utente senza profilo e lo aggiungo alla lista
	utenti->push_back(new User(u));

	return true;
}


bool Legami::login(const User& u)
{
	if(utenti)
	{
		// se il nick esiste controllo la password
		for(unsigned int i=0; i<utenti->size(); ++i)
		{
			if( *(*utenti)[i] == u )
				return true;
		}
	}

	return false; // se non c'è un db o il for esce senza return
}

