#include "Problem_19.h"
#include <cstdio>

namespace pp = project_euler::problems;

const int DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

pp::Problem_19::Problem_19() {}

pp::Problem_19::~Problem_19() {}

void pp::Problem_19::sundays() const {
    // First sunday date.
    int day = 7;
    int month = 1;
    int year = 1900;
    int counter = 0;

    while (day <= 31 && month <= 12 && year <= 2000) {
        day += 7;
		
        int days_in_month = DAYS[month - 1];
        if (month == 2 && m_is_leap_year(year))
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

    printf("Total number of Sundays between 1900 to 2000 == [%d]\n", counter);
}

bool pp::Problem_19::m_is_leap_year(int YYYY) const {
    if (YYYY % 4) return false;
    if (YYYY % 100 == 0 && YYYY % 400) return false;

    return true;    
}
