#include <cstdio>
#include <string>
#include <fstream>
#include <cstdlib>

void series_product(const std::string& file_path) {
	std::string number;
	std::ifstream ifs(file_path.c_str());
	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line))
			number += line;
		ifs.close();
	} else {
		printf("There is a problem in opening up [%s] file\n", file_path.c_str());
	}

	int sequence = 13;
	unsigned long long int product = 0;
	for (std::size_t i = 0; i < number.size() - sequence; ++i) {
		unsigned long long int P = 1;
		for (std::size_t j = i; j < sequence + i; ++j) {
			char value[2] = { 0 };
			value[0] = number[j];
			P *= std::atoi(value);
		}
		if (P > product)
			product = P;
	}

	printf("largest sequence product == [%llu]\n", product);
}

int main() {
	series_product("data/largest_product.txt");

	return 0;
}
