#include "Legami.h"


Legami::Legami(string* database, User* u) {}


bool Legami::registra(const User& u)
{
	if(database)
	{
		// se il nick esiste gia ritorno false
		for(unsigned int i=0; i<database->size(); ++i)
		{
			if(*(*database)[i] == u);
				return false;
		}
	}

	else
	{
		// costruisco da zero la lista utenti
		database = new vector<User*>;
	}

	// costruisco un utente senza profilo e lo aggiungo alla lista
	// l'utente aggiungerà in seguito i suoi dati modificando il profilo
	database->push_back(new User(u));

	return true;
}


bool Legami::login(const User& u)
{
	if(database)
	{
		// se il nick esiste controllo la password
		for(unsigned int i=0; i<database->size(); ++i)
		{
			if(*(*database)[i] == u)
				return true;
		}
	}

	// se non c'è un db o il for esce senza return
	return false;
}

