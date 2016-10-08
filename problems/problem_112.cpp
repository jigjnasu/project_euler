/*
  This is solution for problem 112 (Bouncy numbers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 3rd, 2016
 */

#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>

bool is_increasing(const std::string& number) {
	for (std::size_t i = 0; i < number.size() - 1; ++i)
		if (number[i + 1] < number[i])
			return false;
	
	return true;
}

bool is_decreasing(const std::string& number) {
	for (std::size_t i = 0; i < number.size() - 1; ++i)
		if (number[i + 1] > number[i])
			return false;

	return true;
}

float percentage(const int& count, const int& total) {
	return (count / static_cast<float>(total)) * 100.00f;
}

std::string number_to_string(const int& number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

void bouncy_numbers() {
	int count = 0;
	int iter = 10;
	
	while (1) {
		const std::string number = number_to_string(iter);
		if (is_increasing(number) || is_decreasing(number))
			;
		else
			++count;

		if (percentage(count, iter) == 99.00f) {
			printf("---------------------------------------------------\n");
			printf("Bouncy number which is 99 percent of the total == [%d]\n", iter);
			printf("---------------------------------------------------\n");
			break;
		}
		
		++iter;
	}
}

int main() {
	std::clock_t start = clock();
	bouncy_numbers();
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}
