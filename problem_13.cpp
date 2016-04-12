#include "Integer.h"
#include <fstream>

void read_file(std::string file, std::vector<std::string>& numbers) {
	std::ifstream ifs(file.c_str());
	if (ifs.is_open()) {
		std::string number;
		while (std::getline(ifs, number))
			numbers.push_back(number);

		ifs.close();
	} else {
		printf("There is an error while opening [%s] file\n", file.c_str());
	}
}

int main() {
	Integer<int> sum;
	std::vector<std::string> numbers;
	read_file("large_sum.txt", numbers);

	for (std::size_t i = 0; i < numbers[0].size(); ++i)
		printf("%c", numbers[0][i]);
	
	for (std::size_t i = 0; i < numbers.size(); ++i) {
		sum += numbers[i];
	}
	
	sum.Print();
	
	return 0;
}
