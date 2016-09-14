/*
  This is solution for problem 99 (Largest exponential) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : Sep 14th, 2016
*/

#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>

int largest_number(const std::string& file) {
    std::ifstream ifs(file.c_str());
    int line_number = 1;
    double max_number = 0;
    int max_line_number = 0;
    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            const std::size_t pos = line.find(",");
            const int base = std::atoi(line.substr(0, pos + 1).c_str());
            const int exp = std::atoi(line.substr(pos + 1, line.size() - pos).c_str());
            const double number = exp * std::log(base);
            if (number > max_number) {
                max_line_number = line_number;
                max_number = number;
            }

            ++line_number;
        }

        ifs.close();
    } else {
        printf("Error in opening [%s] file\n", file.c_str());
    }

    return max_line_number;
}

int main() {
    std::clock_t start = clock();
    printf("-----------------------------------------------------\n");
    printf("largest line number == [%d]\n", largest_number("data/base_exp.txt"));
    printf("-----------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
    return 0;
}
