/*
  This is solution for problem 40 (Champernowne's constant) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 14th, 2016
 */

#include <cstdio>
#include <string>
#include <sstream>
#include <ctime>

std::string number_to_string(const int& N) {
	std::stringstream ss;
	ss << N;
	return ss.str();
}

void champernowne_constant() {
	std::string number;
	int i = 1;
	while (number.size() < 1000000)
		number += number_to_string(i++);

	printf("-----------------------------------------------------\n");
	printf("%c %c %c %c %c %c %c\n", number[0], number[9], number[99], number[999], number[9999], number[99999], number[999999]);
	printf("Champernowne Constant == [%d]\n", (number[0] - '0') *
		   (number[9] - '0') * (number[99] - '0') * (number[999] - '0') *
		   (number[9999] - '0') * (number[99999] - '0') * (number[999999] - '0'));
	printf("-----------------------------------------------------\n");
}

int main() {
	std::clock_t start = clock();
	champernowne_constant();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

