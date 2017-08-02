#include "Problem_67.h"
#include <iostream>
#include <sstream>
#include <fstream>

project_euler::problems::Problem_67::Problem_67() {}

project_euler::problems::Problem_67::~Problem_67() {}

void project_euler::problems::Problem_67::max_path() const {
    std::vector<std::vector<int>> pyramid = m_get_pyramid("../data/triangle.txt");

    std::size_t c_size = pyramid[pyramid.size() - 1].size() - 1;
    for (int r = pyramid.size() - 2; r >= 0; --r, --c_size)
        for (std::size_t c = 0; c < c_size; ++c)
            pyramid[r][c] += m_max(pyramid[r + 1][c], pyramid[r + 1][c + 1]); 

    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Running down the pyramid maximum path == " << pyramid[0][0]  << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;    
}

std::vector<std::vector<int>>
project_euler::problems::Problem_67::m_get_pyramid(const std::string& file) const {
    std::vector<std::vector<int>> pyramid;
    std::ifstream ifs(file);
    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            std::vector<int> row;
            std::istringstream iss(line);
            int value = 0;
            while (iss >>value)
                row.push_back(value);
            pyramid.push_back(row);
        }
    } else {
        std::cout << "There is a problem in opening " << file << std::endl;
    }

    return pyramid;
}

int project_euler::problems::Problem_67::m_max(int a, int b) const {
    return a > b ? a : b;
}
