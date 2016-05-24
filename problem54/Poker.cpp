#include "../common/QuickSort.h"
#include "Poker.h"
#include <cstdio>

const std::string CARD_VALUE = "0123456789TJQKA";
const std::string CARD_TYPE  = "CDHS";

PROJECT_EULER::Poker::Poker() {}

PROJECT_EULER::Poker::~Poker() {}

int PROJECT_EULER::Poker::Winner(const std::string& hands) {
	Hand player1;
	Hand player2;

	m_parseHands(hands, player1, player2);
	const int winner = m_findWinner(player1, player2);
	printf("Winner == [%d]\n", winner);
	return winner;
}

void PROJECT_EULER::Poker::m_parseHands(const std::string& hands,
										Hand& player1, Hand& player2) {
	std::size_t i = 0;
	int first_player_hands_count = 0;
	while (i < hands.size()) {
		if (hands[i] == ' ') {
			++i;
			continue;
		}

		if (first_player_hands_count < 5) {
			player1.value.push_back(m_getCardValue(hands[i]));
			player1.type  += hands[i + 1];
			++first_player_hands_count;
		} else {
			player2.value.push_back(m_getCardValue(hands[i]));
			player2.type  += hands[i + 1];			
		}

		i += 2;
	}
}

int PROJECT_EULER::Poker::m_findWinner(const Hand& player1, const Hand& player2) {
	Rank rank1;
	Rank rank2;
	m_getPlayerRanking(player1, rank1);
	m_getPlayerRanking(player2, rank2);

	return m_calculateWinner(rank1, rank2);
}

void PROJECT_EULER::Poker::m_getPlayerRanking(const Hand& player, Rank& rank) {
	// Check for Royal Flush
	if (m_royalFlush(player)) {
		rank.type = ROYAL_FLUSH;
		rank.card = player.type[0];
		return;
	}

	// Check for Straight Flush
	if (m_straightFlush(player)) {
		rank.type = STRAIGHT_FLUSH;
		rank.card = player.type[0];
		rank.value = player.value[0];
		return;
	}

	// Check for Four Of A Kind
	int result = 0;
	if (m_fourOfAKind(player, result)) {
		rank.type = FOUR_OF_A_KIND;
		rank.value = result;
		return;
	}

	result = 0;
	// Check for Full House
	if (m_fullHouse(player, result)) {
		rank.type = FULL_HOUSE;
		rank.value = result;
		return;
	}

	// Check for Flush
	if (m_flush(player)) {
		rank.type = FLUSH;
		rank.card = player.type[0];
		return;
	}

	// Check for Straight
	if (m_straight(player)) {
		rank.type = STRAIGHT;
		return;
	}

	result = 0;
	// Check for Three Of A Kind
	if (m_threeOfAKind(player, result)) {
		rank.type = THREE_OF_A_KIND;
		rank.value = result;
		return;
	}

	// Check for Two Pairs
	if (m_twoPairs(player)) {
		rank.type = TWO_PAIRS;
		return;
	}

	result = 0;
	// Check for One Pair
	if (m_onePair(player, result)) {
		rank.type = ONE_PAIR;
		rank.value = result;
		return;
	}

	// This is the last one, Highest Card.
	rank.type = HIGH_CARD;
	rank.value = m_highCard(player);
}

int PROJECT_EULER::Poker::m_getCardValue(const char card) {
	if (card == 'T')
		return 10;
	else if (card == 'J')
		return 11;
	else if (card == 'Q')
		return 12;
	else if (card == 'K')
		return 13;
	else if (card == 'A')
		return 14;
	else
		return card - '0';
}

bool PROJECT_EULER::Poker::m_allCardsSame(const std::string& type) {
	if (type[0] != type[1] ||
		type[0] != type[2] ||
		type[0] != type[3] ||
		type[0] != type[4])
		return false;

	return true;
}

bool PROJECT_EULER::Poker::m_royalFlush(const Hand& player) {
	if (!m_allCardsSame(player.type))
		return false;

	std::vector<int> value = player.value;

	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	for (std::size_t i = 10; i <= 14; ++i)
		if (static_cast<int>(i) != value[i])
			return false;
	

	return true;
}

bool PROJECT_EULER::Poker::m_straightFlush(const Hand& player) {
	if (!m_allCardsSame(player.type))
		return false;

	std::vector<int> value = player.value;

	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);
	
	for (std::size_t i = 0; i < player.value.size() - 1; ++i)
		if (value[i] != value[i + 1] + 1)
			return false;
	
	return true;
}

bool PROJECT_EULER::Poker::m_fourOfAKind(const Hand& player, int& result) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	int compare = value[2];
	int counter = 0;
	for (std::size_t i = 0; i < value.size(); ++i)
		if (compare == value[i])
			++counter;

	if (counter == 4)
		return true;
	else
		return false;
}

bool PROJECT_EULER::Poker::m_fullHouse(const Hand& player, int& result) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	if ( (value[0] == value[1] && value[0] == value[2]) && (value[3] == value[4]) ) {
		result = value[0];
		return true;
	}

	if ( (value[0] == value[1]) && (value[2] == value[3] && value[2] == value[4]) ) {
		result = value[2];
		return true;
	}

	return false;
}

bool PROJECT_EULER::Poker::m_flush(const Hand& player) {
	return m_allCardsSame(player.type);
}

bool PROJECT_EULER::Poker::m_straight(const Hand& player) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	for (std::size_t i = 0; i < value.size() - 1; ++i)
		if (value[i] != value[i + 1] + 1)
			return false;

	return true;
}

bool PROJECT_EULER::Poker::m_threeOfAKind(const Hand& player, int& result) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	for (std::size_t i = 0; i < value.size() - 2; ++i) {
		if (value[i] == value[i + 1] &&
			value[i] == value[i + 2]) {
			result = value[i];
			return true;
		}
	}

	return false;
}

bool PROJECT_EULER::Poker::m_twoPairs(const Hand& player) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	int pairs = 0;
	for (std::size_t i = 0; i < value.size() - 1; ++i) {
		if (value[i] == value[i + 1]) {
			++pairs;
			++i;
		}
	}

	if (pairs == 2)
		return true;
	else
		return false;
}

bool PROJECT_EULER::Poker::m_onePair(const Hand& player, int& result) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	for (std::size_t i = 0; i < value.size() - 1; ++i) {
		if (value[i] == value[i + 1]) {
			result = value[i];
			return true;
		}
	}

	return false;
}

int PROJECT_EULER::Poker::m_highCard(const Hand& player) {
	std::vector<int> value = player.value;
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	sort.Sort(value);

	return value[4];
}

int PROJECT_EULER::Poker::m_calculateWinner(const Rank& rank1, const Rank& rank2) {
	// Check for Royal House
	if (rank1.type == ROYAL_FLUSH)
		return 1;
	if (rank2.type == ROYAL_FLUSH)
		return 2;

	// Check for Straight Flush
	if (rank1.type == STRAIGHT_FLUSH)
		return 1;
	if (rank2.type == STRAIGHT_FLUSH)
		return 2;

	// Check for Four Of A Kind if both have same, check card value
	if (rank1.type == FOUR_OF_A_KIND && rank2.type == FOUR_OF_A_KIND) {
		if (rank1.value > rank2.value)
			return 1;
		else
			return 2;
	} 

	// Check for Four of A Kind
	if (rank1.type == FOUR_OF_A_KIND)
		return 1;
	if (rank2.type == FOUR_OF_A_KIND)
		return 2;

	// Check for Full house and its value
	if (rank1.type == FULL_HOUSE && rank2.type == FULL_HOUSE) {
		if (rank1.value > rank2.value)
			return 1;
		else
			return 2;
	}

	// Check for Full House
	if (rank1.type == FULL_HOUSE)
		return 1;
	if (rank2.type == FULL_HOUSE)
		return 2;

	// Check for Flush
	if (rank1.type == FLUSH)
		return 1;
	if (rank2.type == FLUSH)
		return 2;

	// Check for Straight
	if (rank1.type == STRAIGHT)
		return 1;
	if (rank2.type == STRAIGHT)
		return 2;

	// Check Three Of A Kind, if both have
	if (rank1.type == THREE_OF_A_KIND && rank2.type == THREE_OF_A_KIND) {
		if (rank1.value > rank2.value)
			return 1;
		else
			return 2;
	}

	// Check for Three Of A Kind
	if (rank1.type == THREE_OF_A_KIND)
		return 1;
	if (rank2.type == THREE_OF_A_KIND)
		return 2;

	// Check for Two Pairs
	if (rank1.type == TWO_PAIRS)
		return 1;
	if (rank2.type == TWO_PAIRS)
		return 2;

	// Check for one pair if both have
	if (rank1.type == ONE_PAIR && rank2.type == ONE_PAIR) {
		if (rank1.value > rank2.value)
			return 1;
		else
			return 2;
	}

	// Check for One Pair
	if (rank1.type == ONE_PAIR)
		return 1;
	if (rank2.type == ONE_PAIR)
		return 2;

	// Last one Highest Card.
	if (rank1.type == HIGH_CARD && rank2.type == HIGH_CARD) {
		if (rank1.value > rank2.value)
			return 1;
		else
			return 2;
	}

	return 0;
}
