/*
  This is solution for problem 99 (Largest exponential) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 29th, 2016
 */

#include "common/Integer.h"
#include <cstdio>
#include <string>
#include <ctime>
#include <fstream>

int largest_number(const std::string& file) {
	std::ifstream ifs(file.c_str());
	if (ifs.is_open()) {
		std::string line;
		std::getline(ifs, line);
		const std::size_t pos = line.find(",");
		const int base = std::atoi(line.substr(0, pos + 1).c_str());
		const int exp = std::atoi(line.substr(pos + 1, line.size() - pos).c_str());

		printf("base == [%d] || exp == [%d]\n", base, exp);
		PROJECT_EULER::COMMON::Integer<int> number(base);
		for (int i = 0; i < 100000; ++i)
			number *= base;
		printf("%s\n", number.GetStringData().c_str());

		ifs.close();
	} else {
		printf("Error in opening [%s] file\n", file.c_str());
	}

	return 0;
}

int main() {
	std::clock_t start = clock();
	printf("-----------------------------------------------------\n");
	printf("largest line number == [%d]\n", largest_number("data/base_exp.txt"));
	printf("-----------------------------------------------------\n");
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}
