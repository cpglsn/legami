/*
	questa classe gestisce i dati personali dello user
*/

#ifndef PROFILO_H
#define PROFILO_H

#include <string>

using std::string;

class Profilo
{
	public:
		Profilo(string="", string="", string="", string="", string="", string="", int=0, int=0, int=0);

		bool operator==(const Profilo&);

		static Profilo* leggi(string);
		string scrivi() const;

		void setNome(string);
		void setCognome(string);
		void setLavPrec(string);
		void setLavAtt(string);
		void setTelefono(string);
		void setMail(string);
		void setAnnoNascita(int);
		void setMeseNascita(int);
		void setGiornoNascita(int);

	private:
		string nome, cognome, telefono, mail, lavoro_precedente, lavoro_attuale;
		int anno_nascita, mese_nascita, giorno_nascita;
};

#endif

