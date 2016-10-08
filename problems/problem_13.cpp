#include "common/Integer.h" // This file is in common folder
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <ctime>

void large_sum(const std::string& file) {
    PROJECT_EULER::COMMON::Integer sum;
    std::fstream ifs(file.c_str());
    if (ifs.is_open()) {
	std::string line;
	while (std::getline(ifs, line)) {
	    sum += line;
	}
	sum.Print();
	ifs.close();
    } else {
	printf("There is an error while %s opening the file\n", file.c_str());
    }
}

int main() {
    std::clock_t start = clock();
    large_sum("data/large_sum.txt");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
    return 0;
}
