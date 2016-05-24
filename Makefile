test : problem_54.cpp problem54/Poker.cpp
	g++ -g -c -Wall problem54/Poker.cpp
	g++ -g -c -Wall problem_54.cpp
	g++ -o test problem_54.o Poker.o

clean:
	rm -rf *.o *test*
