#Name: Noam Itzhaki
#ID: 315773465
#Name: Jonathan Schwarz
#ID: 203672910

a.out: compileAll
	g++ *.o -o ../../exe/Server.out -pthread
	rm -f *.o

compileAll: *.h *.cpp
	    g++ -c *.cpp

run:
	./a.out
