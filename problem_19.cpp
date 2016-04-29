#include <cstdio>
#include <ctime>

const int DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(const int& YYYY) {
	if (YYYY % 4) return false;
	if (YYYY % 100 == 0 && YYYY % 400) return false;

	return true;
}

int count_sundays() {
	// First sunday date.
	int day = 7;
	int month = 1;
	int year = 1900;
	int counter = 0;

	while (day <= 31 && month <= 12 && year <= 2000) {

		day += 7;
		
		int days_in_month = DAYS[month - 1];
		if (month == 2 && is_leap_year(year))
			++days_in_month;

		if (day > days_in_month) {
			day -= days_in_month;
			++month;
			
			if (month > 12) {
				++year;
				month = 1;
			}
		}
		
		if (day == 1 && year >= 1901)
			++counter;
	}

	return counter;
}

int main() {
	std::clock_t start = clock();
	printf("Total number of sundays == [%d]\n", count_sundays());
	printf("Execution time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
	return 0;
}
