#include "common/Search.h"
#include <cstdio>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

void get_coded_triangle_numbers(std::vector<int>& numbers) {
	for (int i = 1; i <= 100; ++i)
		numbers.push_back((i * (i + 1)) / 2);
}

int get_word_value(const std::string& word) {
	int value = 0;
	for (std::size_t i = 0; i < word.size(); ++i)
		value += word[i] - 'A' + 1;
	return value;
}

void count(const std::string& path) {
	int counter = 0;
	PROJECT_EULER::COMMON::Search<int> search;
	std::vector<int> coded_triangle_numbers;
	get_coded_triangle_numbers(coded_triangle_numbers);
	
	std::ifstream ifs(path.c_str());
	if (ifs.is_open()) {
		std::string line;
		std::getline(ifs, line);

		int pos = line.find(",");
		if (search.search(coded_triangle_numbers, get_word_value(line.substr(1, pos - 2))))
			++counter;
		
		while (pos != std::string::npos) {
			std::size_t next_pos = line.find(",", pos + 1);
			if (next_pos == std::string::npos) {
				if (search.search(coded_triangle_numbers, get_word_value(line.substr(pos + 2, line.size() - pos - 3))))
					++counter;
			} else {
				if (search.search(coded_triangle_numbers, get_word_value(line.substr(pos + 2, next_pos - pos - 3))))
					++counter;
			}
			pos = next_pos;
		}
	} else {
		printf("There is a problem in opening the [%s] file\n", path.c_str());
	}

	printf("Coded trinalge numbers count == [%d]\n", counter);
}

int main() {
	std::clock_t start = clock();
	count("data/words.txt");
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}
