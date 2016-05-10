#include <cstdio>
#include <ctime>
#include <string>

const int MILLION = 1000000;

bool is_palindrome(const std::string& number) {
	int i = 0;
	int j = number.size() - 1;
	while (i < j)
		if (number[i++] != number[j--])
			return false;

	return true;
}

std::string binary(const int& N) {
	std::string number;
	int i = 0;
	while (1) {
		int index = 1 << i;
		if (index > N)
			break;
		if (N & index)
			number.push_back('1');
		else
			number.push_back('0');
		++i;
	}

	return number;
}

std::string convert_number(int N) {
	std::string number;
	while (N) {
		number.push_back(N % 10 + '0');
		N /= 10;
	}
	
	return number;
}

int main() {
	std::clock_t start = clock();
	unsigned long long int sum = 0;
	for (int i = 1; i < MILLION; ++i)
		if (is_palindrome(binary(i)) && is_palindrome(convert_number(i)))
			sum += i;

	printf("Sum of all binary and decimal numbers under million == [%llu]\n", sum);
	
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}
