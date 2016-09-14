/*
  This is solution for problem 56 (Powerful digit sum) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 25th, 2016
*/

#include "common/Integer.h"
#include <string>
#include <cstdio>
#include <ctime>

typedef unsigned long long int u_longi;

u_longi get_sum(const std::string& number) {
    u_longi sum = 0;
    for (std::size_t i = 0; i < number.size(); ++i)
	sum += number[i] - '0';

    return sum;
}

void powerful_digit_sum() {
    u_longi max_sum = 0;
    for (int a = 2; a < 100; ++a) {
	Integer number(1);
	for (int i = 0; i < 100; ++i) {
	    number *= a;
			
	    u_longi sum = get_sum(number.GetReverse());
	    if (sum > max_sum)
		max_sum = sum;
	}
		
    }

    printf("-----------------------------------------------------------------\n");
    printf("Powerful Digit Max Sum == [%llu]\n", max_sum);
    printf("-----------------------------------------------------------------\n");
}

int main() {
    std::clock_t start = clock();
    powerful_digit_sum();
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    return 0;
}
