#include "Problem_22.h"
#include "MergeSort.h"
#include "String.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

namespace pp = project_euler::problems;

pp::Problem_22::Problem_22() {}

pp::Problem_22::~Problem_22() {}

void pp::Problem_22::names_scores(const std::string& file) const {
    unsigned long long int score = 0;
    std::vector<std::string> names;
	
    std::fstream ifs(file.c_str());
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);

        std::size_t pos = line.find(",");
        names.push_back(line.substr(1, pos - 2));

        while (pos != std::string::npos) {
            std::size_t next_pos = line.find(",", pos + 1);
            if (next_pos == std::string::npos)
                names.push_back(line.substr(pos + 2, line.size() - pos - 3));
            else
                names.push_back(line.substr(pos + 2, next_pos - pos - 3));
            pos = next_pos;
        }

        utility::algorithms::sort::MergeSort<std::string> merge_sort;
        utility::string::String<int> string;
        merge_sort.sort(names);
        
        for (std::size_t i = 0; i < names.size(); ++i)
            score += (i + 1) * string.sum_of_char_value(names[i]);

        printf("Sum of all names == [%llu]\n", score);
    } else {
        printf("There is an error while %s opening the file\n", file.c_str());
    }    
}
