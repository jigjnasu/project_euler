/*
  This is solution for problem 26 (Quadratic primes) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 17th, 2016
 */


#include <cstdio>
#include <string>
#include <vector>
#include <ctime>

bool is_in_dictionary(const std::vector<int>& dictionary, const int& key, int& pos) {
	for (std::size_t i = 0; i < dictionary.size(); ++i) {
		if (key == dictionary[i]) {
			pos = i;
			return true;
		}
	}

	return false;
}

int get_max_recurence_count(const std::string& number) {
	std::size_t start_pos = number.find("(");
	if (start_pos == std::string::npos)
		return 0;

	return number.find(")") - start_pos;
}

std::string fraction(int X, int Y) {
	int counter = 1;
	X *= 10;
	std::vector<int> dictionary;
	dictionary.push_back(1);

	std::string result = "0.";

	while (1) {		
		while (X < Y) {
			X *= 10;
			++counter;
			if (counter > 1) {
				dictionary.push_back(0);
				result += "0";
			}
		}
		counter = 0;

		const int remainder = X % Y;
		result.push_back((X / Y) + '0');
		
		if (remainder == 0)
			break;

		int pos = 0;
		// recurence case
		if (is_in_dictionary(dictionary, remainder, pos)) {
			result.insert(pos + 2, "(");
			result += ")";
			break;
		}

		dictionary.push_back(remainder);

		X = remainder;
	}

	return result;
}

int main() {
	std::clock_t start = clock();
	int max_number = 0;
	int max_recurence = 0;
	std::string max_fraction;	
	
	for (int i = 2; i < 1000; ++i) {
		const std::string str_fraction = fraction(1, i);
		const int count = get_max_recurence_count(str_fraction);
		if (count > max_recurence) {
			max_number = i;
			max_recurence = count;
			max_fraction = str_fraction;
		}
	}

	printf("---------------------------------------------------------------------------------------------------\n");
	printf("1 / [%d] has maximum recurence of [%d]\n", max_number, max_recurence);
	printf("fraction == [%s]\n", max_fraction.c_str());
	printf("---------------------------------------------------------------------------------------------------\n");	
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}
