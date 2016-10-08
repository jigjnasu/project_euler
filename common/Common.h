#ifndef PROJECT_EULER_COMMON_INC_COMMON_H_
#define PROJECT_EULER_COMMON_INC_COMMON_H_

#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

namespace PROJECT_EULER {
    namespace COMMON {
        template <typename T>
            class Common {
        public:
            Common();
            ~Common();

            void PrintVector(const std::vector<T>& V);
            bool IsPrime(const T& number);
            const std::string ToString(const T& number);
            const T ToNumber(const std::string& number);
        };
    };
};

namespace PC = PROJECT_EULER::COMMON;

template <typename T>
PC::Common<T>::Common() {}

template <typename T>
PC::Common<T>::~Common() {}

template <typename T>
void PC::Common<T>::PrintVector(const std::vector<T>& V) {
    for (std::size_t i = 0; i < V.size(); ++i)
        std::cout << V[i] << " ";
    std::cout << std::endl;
}

template <typename T>
bool PC::Common<T>::IsPrime(const T& number) {
    if (number == 2)
        return true;
	
    for (int i = 2; i <= std::sqrt(number); ++i)
        if (number % i == 0)
            return false;
	
    return true;
}

template <typename T>
const std::string PC::Common<T>::ToString(const T& number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

template <typename T>
const T PC::Common<T>::ToNumber(const std::string& number) {
    std::stringstream ss;
    ss << number;
    T num = 0;
    ss >> num;
    return num;
}

#endif // PROJECT_EULER_COMMON_INC_COMMON_H_
