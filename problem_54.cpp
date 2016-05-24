/*
  This is solution for problem 54 () from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 24th, 2016
 */

#include "problem54/Poker.h"
#include <cstdio>
#include <ctime>
#include <fstream>

void poker_hands(const std::string& file) {
	int winner1_counter = 0;
	PROJECT_EULER::Poker poker;
	std::ifstream ifs(file.c_str());

	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line)) {
			if (poker.Winner(line) == 1)
				++winner1_counter;
		}
			
		ifs.close();
	} else {
		printf("There is an error while opening [%s] file\n", file.c_str());
	}

	printf("Winner 1 from all games == [%d]\n", winner1_counter);
}


int main() {
	std::clock_t start = clock();
	poker_hands("data/poker.txt");
	printf("Execution time == [%.6f] seconds\n", (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}
