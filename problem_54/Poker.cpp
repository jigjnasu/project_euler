/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.
  This is the implementation of Poker Class
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 26th, 2016
*/

#include "Poker.h"
#include "QuickSort.h"
#include <cstdio>
#include <string>
#include <vector>

// Constants for ranks
const int ROYAL_FLUSH_RANK 		= 1;
const int STRAIGHT_FLUSH_RANK	= 2;
const int FOUR_OF_A_KIND_RANK	= 3;
const int FULL_HOUSE_RANK		= 4;
const int FLUSH_RANK		  	= 5;
const int STRAIGHT_RANK			= 6;
const int THREE_OF_A_KIND_RANK	= 7;
const int TWO_PAIRS_RANK		= 8;
const int ONE_PAIR_RANK			= 9;
const int HIGH_CARD_RANK		= 10;

Poker::Poker() {}

Poker::~Poker() {}

int Poker::Winner(const std::vector<Card>& A, const std::vector<Card>& B) {
	int winner = 1;
	int max_player_1 = 0;
	int max_player_2 = 0;
	
	const int player_1_rank = m_get_rank(A, max_player_1);
	const int player_2_rank = m_get_rank(B, max_player_2);

	if (player_1_rank == player_2_rank) {
		if (max_player_1 == max_player_2) {
			winner = m_find_max_winner(A, B);
		} else {
			if (max_player_2 > max_player_1)
				winner = 2;
		}
	} else if (player_1_rank > player_2_rank) {
		winner = 2;
	}

	return winner;	
}

bool Poker::m_is_royal_flush(const std::vector<Card>& hands, int& max) {
	if (false == m_is_same_suit(hands))
		return false;
	
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);
	
	for (std::size_t i = 0; i < values.size(); ++i)
		if (values[i] != i + 10)
			return false;

	return true;	
}

bool Poker::m_is_straight_flush(const std::vector<Card>& hands, int& max) {
	if (false == m_is_same_suit(hands))
		return false;
	
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	for (std::size_t i = 0; i < values.size() - 1; ++i)
		if (values[i + 1] - values[i] != 1)
			return false;

	max = values[4];
	return true;
}

bool Poker::m_is_four_of_a_kind(const std::vector<Card>& hands, int& max) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	if (values[0] == values[1] &&
		values[0] == values[2] &&
		values[0] == values[3]) {
		max = values[0];
		return true;
	}

	if (values[1] == values[2] &&
		values[1] == values[3] &&
		values[1] == values[4]) {
		max = values[1];
		return true;
	}

	return false;	
}

bool Poker::m_is_full_house(const std::vector<Card>& hands, int& max) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	// Case if AAABB
	if ( (values[0] == values[1]  &&
		  values[0] == values[2]) &&
		 (values[3] == values[4]) ) {
		max = values[0];
		return true;
	}

	// Case if AABBB
	if ( (values[0] == values[1]) &&
		 (values[2] == values[3] &&
		  values[2] == values[4]) ) {
		max = values[2];
		return true;
	}

	return false;	
}

bool Poker::m_is_flush(const std::vector<Card>& hands, int& max) {
	return m_is_same_suit(hands);	
}

bool Poker::m_is_straight(const std::vector<Card>& hands, int& max) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	for (std::size_t i = 0; i < values.size() - 1; ++i)
		if (values[i + 1] - values[i] != 1)
			return false;

	max = values[4];
	return true;	
}

bool Poker::m_is_three_of_a_kind(const std::vector<Card>& hands, int& max) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);
	
	// Case if AAABC
	if (values[0] == values[1] && values[0] == values[2]) {
		max = values[0];
		return true;
	}

	// Case if ABBBC
	if (values[1] == values[2] && values[1] == values[3]) {
		max = values[1];
		return true;
	}

	// Case if ABCCC
	if (values[2] == values[3] && values[2] == values[4]) {
		max = values[2];
		return true;
	}
	
	return false;	
}

bool Poker::m_is_two_pairs(const std::vector<Card>& hands, int& max) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	// Case of ABBCC
	if ( (values[1] == values[2]) && (values[3] == values[4]) ) {
		max = values[1];
		return true;
	}

	// Case of AABCC
	if ( (values[0] == values[1]) && (values[3] == values[4]) ) {
		max = values[0];
		return true;
	}

	// Case if AABBC
	if ( (values[0] == values[1]) && (values[2] == values[3]) ) {
		max = values[0];
		return true;
	}

	return false;	
}

bool Poker::m_is_one_pair(const std::vector<Card>& hands, int& max) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	for (std::size_t i = 0; i < values.size() - 1; ++i) {
		if (values[i] == values[i + 1]) {
			max = values[i];
			return true;
		}
	}

	return false;	
}

int Poker::m_find_max_value(const std::vector<Card>& hands, const int& index) {
	std::vector<int> values;
	for (std::size_t i = 0; i < hands.size(); ++i)
		values.push_back(hands[i].Value());

	QuickSort<int> sort;
	sort.Sort(values);

	return values[4 - index];	
}

int Poker::m_find_max_winner(const std::vector<Card>& A, const std::vector<Card>& B) {
	int winner = 1;
	for (int i = 0; i < 4; ++i) {
		const int player_1_max = m_find_max_value(A, i);
		const int player_2_max = m_find_max_value(B, i);
		
		if (player_1_max != player_2_max) {
			if (player_2_max > player_1_max)
				winner = 2;
			break;
		}
	}
	
	return winner;	
}

int Poker::m_get_rank(const std::vector<Card>& hands, int& max) {
	int rank = HIGH_CARD_RANK;
	
	if (m_is_royal_flush(hands, max))
		rank = ROYAL_FLUSH_RANK;
	else if (m_is_straight_flush(hands, max))
		rank = STRAIGHT_FLUSH_RANK;
	else if (m_is_four_of_a_kind(hands, max))
		rank = FOUR_OF_A_KIND_RANK;
	else if (m_is_full_house(hands, max))
		rank = FULL_HOUSE_RANK;
	else if (m_is_flush(hands, max))
		rank = FLUSH_RANK;
	else if (m_is_straight(hands, max))
		rank = STRAIGHT_RANK;
	else if (m_is_three_of_a_kind(hands, max))
		rank = THREE_OF_A_KIND_RANK;
	else if (m_is_two_pairs(hands, max))
		rank = TWO_PAIRS_RANK;
	else if (m_is_one_pair(hands, max))
		rank = ONE_PAIR_RANK;

	return rank;	
}

bool Poker::m_is_same_suit(const std::vector<Card>& hands) {
	if (hands[0].Type() != hands[1].Type() ||
		hands[0].Type() != hands[2].Type() ||
		hands[0].Type() != hands[3].Type() ||
		hands[0].Type() != hands[4].Type())
		return false;
	
	return true;	
}
