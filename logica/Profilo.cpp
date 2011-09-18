#include "Profilo.h"
#include "Xml.h"


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



Profilo* Profilo::leggi(string s)
{
	string n = tag(s, "<nome>", "</nome>");
	string c = tag(s, "<cognome>", "</cognome>");
	string t = tag(s, "<telefono>", "</telefono>");
	string ma = tag(s, "<mail>", "</mail>");
	string lp = tag(s, "<lav_prec>", "</lav_prec>");
	string la = tag(s, "<lav_att>", "</lav_att>");
	int a = string_to_int(tag(s, "<anno>", "</anno>"));
	int m = string_to_int(tag(s, "<mese>", "</mese>"));
	int g = string_to_int(tag(s, "<giorno>", "</giorno>"));

	return new Profilo(n, c, t, ma, lp, la, a, m, g);
}



string Profilo::scrivi() const
{
	return 	"<nome>" + nome + "</nome>" +
				"<cognome>" + cognome + "</cognome>" +
				"<telefono>" + telefono + "</telefono>" +
				"<mail>" + mail + "</mail>" +
				"<lav_prec>" + lavoro_precedente + "</lav_prec>" +
				"<lav_att>" + lavoro_attuale + "</lav_att>" +
				"<anno>" + int_to_string(anno_nascita) + "</anno>" +
				"<mese>" + int_to_string(mese_nascita) + "</mese>" +
				"<giorno>" + int_to_string(giorno_nascita) + "</giorno>";
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

