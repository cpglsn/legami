all: Contatto.o Gruppo.o Profilo.o User.o


Contatto.o: Contatto.h Contatto.cpp User.o
	g++ -c Contatto.cpp

Gruppo.o: Gruppo.h Gruppo.cpp User.o
	g++ -c Gruppo.cpp

Profilo.o: Profilo.h Profilo.cpp
	g++ -c Profilo.cpp

User.o: User.h User.cpp
	g++ -c User.cpp


clean:
	rm *.o *.gch
