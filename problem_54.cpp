/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 25th, 2016
 */

#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

const string CARD_TYPE = "CDHS";
costt string CARD_VALUE = "23456789TJQKA";

struct Card {
	char type;
	char value;
};

void read_data(const std::string& file_name,
			   std::vector< std::vector<Card> >& A,
			   std::vector< std::vector<Card> >& B>) {
	std::ifstream ifs(file_name);
	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line))
			printf("%s\n", line.c_str());
	} else {
		printf("Error: There is an error while [%s] file\n", file_name.c_str());
	}
}

int main() {
	std::vector< std::vector<Card> > A;
	std::vector< std::vector<Card> > B;
	
	read_data(data/poker.txt, A, B);

	return 0;
}
