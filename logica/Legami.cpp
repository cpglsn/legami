#include "Legami.h"
#include "Xml.h"
#include "BusinessUser.h"
#include "ExecutiveUser.h"
#include "Gruppo.h"



Legami::Legami(vector<User*>* db, User* u)
	: database(db)
	, user(u)
{

}



void Legami::leggi(vector<string>* v)
{
	vector<User*>* vu = new vector<User*>;

	// aggiungo gli user senza la lista contatti e gruppi
	for(unsigned int i=0; i< v->size()-1; ++i)
	{
		// l'ultima riga e' per i gruppi
		string ruolo = tag((*v)[i], "<ruolo>", "</ruolo>");

		// all'interno del tag User ci sono nick, password e profilo dello user
		// ma non i gruppi o i collegamenti, perchè devo prima popolare la base
		// di dati con tutti gli user per garantire uno stato consistente del db
		string s = tag((*v)[i], "<user>", "</user>");
		User* user = User::leggi(s);

		// ora leggo il profilo dello user
		s = tag((*v)[i], "<profilo>", "</profilo>");
		Profilo* p = Profilo::leggi(s);

		// collego il profilo allo user
		user->profilo = p;

		// aggiungo lo user nel db
		if(ruolo == "base")
			vu->push_back(user);

		else if(ruolo == "business")
			vu->push_back(new BusinessUser(*user));

		else if(ruolo == "executive")
			vu->push_back(new ExecutiveUser(*user));
	}

	// assegno il db all'oggetto di legami
	database = vu;

	// collegamenti
	for(unsigned int i=0; i < v->size()-1; ++i)
	{
		string s = (*v)[i];

		string c = tag(s, "<collegamenti>", "</collegamenti>");
		int num_coll = string_to_int(tag(c, "<numeroColl>", "</numeroColl>"));

		for(int j = 0; j < num_coll; ++j)
		{
			string t = tag(c, "<C" + int_to_string(j+1) + ">", "</C" + int_to_string(j+1) + ">");
			string n = tag(t, "<nick>", "</nick>");
			string ta = tag(t, "<tag>", "</tag>");
			// cerco lo user con quel nick per aggiungere il puntatore al vettore dei collegamenti
			for(unsigned int k=0; k<database->size(); ++k)
			{
				if( ((*database)[k])->getNick() == n )
					((*database)[i])->insertContatto(new Contatto( ((*database)[k]), ta) );
			}
		}
	}

	// gruppi (sono alla fine del file)

	string s = (*v)[v->size()-1];

	string group = tag(s, "<gruppi>", "</gruppi>");
	if(!group.empty())
	{
		int num_gr = string_to_int( tag(group, "<numeroGr>", "</numeroGr>"));

		for(int i = 0; i<num_gr; ++i)
		{
			// i-esimo gruppo
			string t = tag(group,	"<G" + int_to_string(i+1) + ">", "</G" + int_to_string(i+1) + ">");

			string nomegr = tag(t, "<nomeGr>", "</nomeGr>");

			string descgr = tag(t, "<descGr>", "</descGr>");

			int numeroMembri = string_to_int(tag(t, "<numeroMembri>", "</numeroMembri>"));

			Gruppo* g = new Gruppo(nomegr, descgr, new vector<User*>);

			for(int j=0; j<numeroMembri; ++j)
			{
				// j-esimo membro dell'i-esimo gruppo
				string w = tag(t, "<" + int_to_string(j+1) + ">", "</" + int_to_string(j+1) + ">");

				string nick = tag(w, "<nick>", "</nick>");

				// cerco lo user con quel nick
				for(unsigned int k=0; k<database->size(); ++k)
				{
					if( ((*database)[k])->getNick() == nick )
					{
						// aggiungo lo user alla lista degli appartenenti al gruppo
						g->aggiungi((*database)[k]);
						// aggiungo il gruppo alla lista dei gruppi dello user
						((*database)[k])->insertGruppo(g);
					}
				}
			}
		}
	}

}



string Legami::scrivi() const
{
	if(database && database->size())
	{
		string s = "";

		for(unsigned int i=0; i<database->size(); ++i)
		{
			s += "<ruolo>";
			s += ( (*database)[i]->getRuolo() );
			s += "</ruolo>";
			s += (*database)[i]->scrivi() + "\n";
		}

		vector<Gruppo*>* gr = elencoGruppi();
		s += "<gruppi>";
		s += "<numeroGr>" + int_to_string(gr->size()) + "</numeroGr>";
		for(unsigned int i=0; i<gr->size(); ++i)
			s += "<G" + int_to_string(i+1) + ">" + (*gr)[i]->scrivi() + "</G" + int_to_string(i+1) + ">";

		s += "</gruppi>";

		return s;
	}

	return "";
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



bool Legami::cancella(User* u)
{
	if(u)
	{
		// un utente puo' cancellare solo se stesso
		if(u->gestore && *user==*u)
		{
			// cancello lo user da tutti i collegamenti
			for(unsigned int i=0; i<database->size(); ++i)
			{
				// creo un puntatore temporaneo alla lista dei contatti dell'i-esimo user
				vector<Contatto*>* tmp = ((*database)[i])->collegamenti;

				// cerco nei collegamenti dello user i-esimo se c'e' u e in tale caso lo cancello
				for(unsigned int j=0; j<tmp->size(); ++j)
				{
					if(*u == *( ((*tmp)[j])->getUser() ) )
					{
						// chiamo il distruttore di Contatto
						delete (*tmp)[j];
						tmp->erase(tmp->begin() + j);
					}
				}
			}

			// elimino lo user dal database
			for(unsigned int i=0; i<database->size(); ++i)
			{
				if( *u == (*(*database)[i]) )
				{
					database->erase(database->begin() + i);
					return true;
				}
			}
		}
	}
	return false;
}



bool Legami::login(string n, string p)
{
	if(database)
	{
		for(unsigned int i=0; i<database->size(); ++i)
		{
			// se il nick esiste controllo la password
			if( ((*database)[i])->checkLogin(n,p) )
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



vector<Gruppo*>* Legami::elencoGruppi() const
{
	vector<Gruppo*>* v = new vector<Gruppo*>;

	// aggiungo i gruppi dei vari utenti a v se non sono già presenti
	for(unsigned int i=0; i<database->size(); ++i)
	{
		User* u = (*database)[i];
		for(unsigned int j=0; j<u->gruppi->size(); ++j)
		{
			Gruppo* gr = ((*(u->gruppi))[j]);
			unsigned int contatore = 0;

			for(unsigned int k=0; k<v->size(); ++k)
			{
				// se non ce ne sono di uguali, lo aggiungo
                if( *((*v)[k]) != *gr )
						++contatore;
			}

			if(contatore == v->size())
				v->push_back(gr);
		}
	}
	return v;
}



vector<User*>* Legami::find(Profilo* p) const
{
	if(!p || !database) return 0;

	vector<User*>* match;

	for(unsigned int i=0; i<database->size(); ++i)
	{
		if( *(((*database)[i])->profilo) == *p)
			// aggiunge il puntatore allo user con quel profilo
			match->push_back((*database)[i]);
	}

	return match;
}

