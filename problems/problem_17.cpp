#include <cstdio>
#include <string>
#include <ctime>

const std::string DICTIONARY_A[] = {"one", "two", "three", "four", "five",
								  "six", "seven", "eight", "nine", "ten"};
const std::string DICTIONARY_B[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen",
								  "sixteen", "seventeen", "eighteen", "nineteen"};
const std::string DICTIONARY_C[] = {"twenty", "thirty", "forty", "fifty", "sixty",
								  "seventy", "eighty", "ninety"};

std::string get_count(int N) {
	std::string word;

	if (N >= 1 && N <= 10) {
		word += DICTIONARY_A[N - 1];
	} else if (N >= 11 && N <= 19) {
		word += DICTIONARY_B[N - 11];
	} else if (N >= 20 && N <= 99) {
		word += DICTIONARY_C[(N / 10) - 2];
		N %= 10;
		if (N)
			word += DICTIONARY_A[N - 1];		
	} else if (N >= 100 && N <= 999){
		word += DICTIONARY_A[(N / 100) - 1] + "hundred";
		N %= 100;
		if (N) {
			word += "and";
			word += get_count(N);
		}
	} else {
		word += "onethousand";
	}

	return word;
}

int main() {
	std::clock_t start = clock();
	int count = 0;
	for (int i = 1; i <= 1000; ++i)
		count += get_count(i).size();
	printf("count from 1 to 1000 == [%d]\n", count);
	printf("Execution time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
	return 0;
}
