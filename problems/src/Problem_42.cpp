#include "Problem_42.h"
#include "BinarySearch.h"
#include "String.h"
#include <cstdio>
#include <fstream>

namespace pp = project_euler::problems;

pp::Problem_42::Problem_42() {}

pp::Problem_42::~Problem_42() {}

void pp::Problem_42::count_coded_triangle_numbers(const std::string& file) const {
    int counter = 0;
    utility::algorithms::search::BinarySearch<int> search;
    utility::string::String<int> string;
    std::vector<int> coded_triangle_numbers = m_coded_triangle_numbers();
    
    std::ifstream ifs(file.c_str());
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);

        std::size_t pos = line.find(",");
        if (search.search(coded_triangle_numbers, string.sum_of_char_value(line.substr(1, pos - 2))))
            ++counter;
		
        while (pos != std::string::npos) {
            std::size_t next_pos = line.find(",", pos + 1);
            if (next_pos == std::string::npos) {
                if (search.search(coded_triangle_numbers,
                                  string.sum_of_char_value(line.substr(pos + 2, line.size() - pos - 3))))
                    ++counter;
            } else {
                if (search.search(coded_triangle_numbers,
                                  string.sum_of_char_value(line.substr(pos + 2, next_pos - pos - 3))))
                    ++counter;
            }
            pos = next_pos;
        }
    } else {
        printf("There is a problem in opening the [%s] file\n", file.c_str());
    }

    printf("Coded trinalge numbers count == [%d]\n", counter);
}

std::vector<int> pp::Problem_42::m_coded_triangle_numbers() const {
    std::vector<int> numbers;
    for (int i = 1; i <= 100; ++i)
        numbers.push_back((i * (i + 1)) / 2);
    return numbers;
}
