#include "Legami.h"


Legami::Legami(vector<User*>* db, User* u)
	: database(db)
	, user(u)
{

}


bool Legami::registra(User* u)
{
	if(database)
	{
		for(unsigned int i=0; i<database->size(); ++i)
		{
			// se il nick esiste già, ritorno false
			if(*((*database)[i]) == *u)
				return false;
		}
	}

	else
	{
		// costruisco da zero la lista utenti
		database=new vector<User*>;
	}

	// costruisco un user senza profilo e lo aggiungo alla lista
	// lo user aggiungerà in seguito i suoi dati modificando il profilo
	database->push_back(u);

	return true;
}


bool Legami::login(string n, string p)
{
	if(database)
	{
		// creo un oggetto User temporaneo per il confronto
		User u(n, p);

		for(unsigned int i=0; i<database->size(); ++i)
		{
			// se il nick esiste controllo la password
			if(*(*database)[i] == u)
			{
				(*(*database)[i]).gestore=this;
				user=(*database)[i];
				return true;
			}
		}
	}

	// se non c'è un db o il for esce senza return
	return false;
}


void Legami::logout()
{
	// imposto il gestore dello user a 0 in modo da liberarlo
	user->gestore=0;
	// tolgo il link allo user (logout)
	user=0;
}


vector<User*>* Legami::find(Profilo* p) const
{
	if(!p || !database) return 0;

	vector<User*>* match;

	for(unsigned int i=0; i<database->size(); ++i)
	{
		if(((*database)[i])->profilo==*p)
			// aggiunge il puntatore allo user con quel profilo
			match->push_back((*database)[i]);
	}

	return match;
}

