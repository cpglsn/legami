all: obj/Contatto.o obj/Gruppo.o obj/Profilo.o obj/User.o obj/Legami.o


obj/Contatto.o: logica/Contatto.h logica/Contatto.cpp obj/User.o
	g++ -c logica/Contatto.cpp -o obj/Contatto.o

obj/Gruppo.o: logica/Gruppo.h logica/Gruppo.cpp obj/User.o
	g++ -c logica/Gruppo.cpp -o obj/Gruppo.o

obj/Profilo.o: logica/Profilo.h logica/Profilo.cpp
	g++ -c logica/Profilo.cpp -o obj/Profilo.o

obj/User.o: logica/User.h logica/User.cpp
	g++ -c logica/User.cpp -o obj/User.o

obj/Legami.o: logica/Legami.h logica/Legami.cpp obj/User.o obj/Profilo.o
	g++ -c logica/Legami.cpp -o obj/Legami.o


clean:
	rm */*.o
	rm */*.gch

