#include "Problem_13.h"
#include "Integer.h"
#include <cstdio>
#include <fstream>

namespace pp = project_euler::problems;

pp::Problem_13::Problem_13() {}

pp::Problem_13::~Problem_13() {}

void pp::Problem_13::large_sum(const std::string& file) const {
    utility::integer::Integer sum(0);
    std::fstream ifs(file.c_str());
    if (ifs.is_open()) {
	std::string line;
	while (std::getline(ifs, line))
	    sum += line;

	sum.print();
	ifs.close();
    } else {
	printf("There is an error while %s opening the file\n", file.c_str());
    }
}
