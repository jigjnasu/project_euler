/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.
  This is the implementation of Poker Class
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 26th, 2016
*/

#ifndef PROJECT_EULER_PROBLEM_54_POKER_H_
#define PROJECT_EULER_PROBLEM_54_POKER_H_

#include "Card.h"
#include <vector>

class Poker {
public:
    Poker();
    ~Poker();
	
    int Winner(const std::vector<Card>& A, const std::vector<Card>& B);
	
private:
    bool m_is_royal_flush(const std::vector<Card>& hands, int& max);
    bool m_is_straight_flush(const std::vector<Card>& hands, int& max);
    bool m_is_four_of_a_kind(const std::vector<Card>& hands, int& max);
    bool m_is_full_house(const std::vector<Card>& hands, int& max);
    bool m_is_flush(const std::vector<Card>& hands, int& max);
    bool m_is_straight(const std::vector<Card>& hands, int& max);
    bool m_is_three_of_a_kind(const std::vector<Card>& hands, int& max);
    bool m_is_two_pairs(const std::vector<Card>& hands, int& max);
    bool m_is_one_pair(const std::vector<Card>& hands, int& max);

    int m_find_max_value(const std::vector<Card>& hands, const int& index);
    int m_find_max_winner(const std::vector<Card>& A, const std::vector<Card>& B);

    int m_get_rank(const std::vector<Card>& hands, int& max);

    bool m_is_same_suit(const std::vector<Card>& hands);
};

#endif // PROJECT_EULER_PROBLEM_54_POKER_H_
