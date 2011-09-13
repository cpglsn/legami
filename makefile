all: logica/Contatto.o logica/Gruppo.o logica/Profilo.o logica/User.o


logica/Contatto.o: logica/Contatto.h logica/Contatto.cpp logica/User.o
	g++ -c logica/Contatto.cpp

logica/Gruppo.o: logica/Gruppo.h logica/Gruppo.cpp User.o
	g++ -c logica/Gruppo.cpp

logica/Profilo.o: logica/Profilo.h logica/Profilo.cpp
	g++ -c logica/Profilo.cpp

logica/User.o: logica/User.h logica/User.cpp
	g++ -c logica/User.cpp


clean:
	rm */*.o */*.gch
