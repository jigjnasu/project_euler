/*
  This is solution for problem 79 (Passcode derivation) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 2nd, 2016
 */

#include <cstdio>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

void get_data(std::vector<int>& codes) {
	std::ifstream ifs("data/keylog.txt");

	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line))
			codes.push_back(std::atoi(line.c_str()));
	} else {
		printf("There is an error while opening data/keylog.txt file\n");
	}
}

void get_digit(const int& div, int (&counts)[10], const std::vector<int>& codes) {
	for (std::size_t i = 0; i < codes.size(); ++i)
		++counts[(codes[i] / div) % 10];
}

void passcode_derivation() {
	std::vector<int> codes;
	get_data(codes);

	for (int i = 1; i <=)
	int counts[10] = { 0 };
	get_digit(1, counts, codes);

	for (int i = 0; i < 10; ++i)
		printf("%d ", counts[i]);
	printf("\n");
}

int main() {
	std::clock_t start = clock();
	passcode_derivation();
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}
