#include "Profilo.h"


Profilo::Profilo(string n, string c, string t, string ma, string lp, string la, int a, int m, int g)
	: nome(n)
	, cognome(c)
	, telefono(t)
	, mail(ma)
	, lavoro_precedente(lp)
	, lavoro_attuale(la)
	, anno_nascita(a)
	, mese_nascita(m)
	, giorno_nascita(g)
{

}


bool Profilo::operator==(const Profilo& p)
{
	if(p.nome=="" || nome==p.nome)
		if(p.cognome=="" || cognome==p.cognome)
			if(p.telefono=="" || telefono==p.telefono)
				if(p.mail=="" || mail==p.mail)
					if(p.lavoro_precedente=="" || lavoro_precedente==p.lavoro_precedente)
						if(p.lavoro_attuale=="" || lavoro_attuale==p.lavoro_attuale)
							if(p.anno_nascita==0 || anno_nascita==p.anno_nascita)
								if(p.mese_nascita==0 || mese_nascita==p.mese_nascita)
									if(p.giorno_nascita==0 || giorno_nascita==p.giorno_nascita)
										return true;
	return false;
}


void Profilo::setNome(string s)
{
	nome=s;
}


void Profilo::setCognome(string s)
{
	cognome=s;
}


void Profilo::setLavPrec(string s)
{
	lavoro_precedente=s;
}


void Profilo::setLavAtt(string s)
{
	lavoro_attuale=s;
}


void Profilo::setTelefono(string s)
{
	telefono=s;
}


void Profilo::setMail(string s)
{
	mail=s;
}


void Profilo::setAnnoNascita(int a)
{
	anno_nascita=a;
}


void Profilo::setMeseNascita(int m)
{
	mese_nascita=m;
}


void Profilo::setGiornoNascita(int g)
{
	giorno_nascita=g;
}

