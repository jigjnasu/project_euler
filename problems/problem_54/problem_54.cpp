/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 25th, 2016
 */

#include "Poker.h"
#include <fstream>
#include <ctime>

// Constant values to hold 
const std::string CARD_TYPE = "CDHS";
const std::string CARD_VALUE = "23456789TJQKA";

bool read_data(const std::string& file_name,
			   std::vector< std::vector<Card> >& A,
			   std::vector< std::vector<Card> >& B) {
	bool result = true;
	std::ifstream ifs(file_name.c_str());
	
	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line)) {
			std::vector<Card> player1;
			std::vector<Card> player2;

			int index = -1;
			for (int i = 0; i < 10; ++i) {
				int pos = line.find(" ", index + 1);
				const std::string data = line.substr(index + 1, 2);
				Card C(data[1], CARD_VALUE.find(data[0]) + 2);

				if (i < 5)
					player1.push_back(C);
				else
					player2.push_back(C);
				index = pos;
			}
			A.push_back(player1);
			B.push_back(player2);
		}
			
	} else {
		printf("Error: There is an error while [%s] file\n", file_name.c_str());
		result = false;
	}
	
	return result;
}

void count_player_wins(const int& player) {
	Poker poker;
	int wins_count = 0;
	std::vector< std::vector<Card> > A;
	std::vector< std::vector<Card> > B;
	
	if (read_data("../data/poker.txt", A, B)) {
		for (std::size_t i = 0; i < A.size(); ++i) {
			if (player == poker.Winner(A[i], B[i])) {
				++wins_count;
			} else {
			}
		}
	}

	printf("-------------------------------------------------------------------------\n");
	printf("Player [%d] wins == [%d] mathces out of 1000\n", player, wins_count);
	printf("-------------------------------------------------------------------------\n");
}

int main() {
	std::clock_t start = clock();
	count_player_wins(1);
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}
