/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.  	
  This is the implementation of Card class
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 26th, 2016
*/

#ifndef PROJECT_EULER_PROBLEM_54_CARD_H_
#define PROJECT_EULER_PROBLEM_54_CARD_H_

#include <string>

class Card {
public:
    Card();
    Card(const char& type, const int& value);
    ~Card();

    char Type() const;
    int Value() const;

private:
    char m_type;
    int  m_value;
};

#endif // PROJECT_EULER_PROBLEM_54_CARD_H_
