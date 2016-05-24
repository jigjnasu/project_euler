#ifndef PROJECT_EULER_PROBLEM_54_POKER_H_
#define PROJECT_EULER_PROBLEM_54_POKER_H_

#include <vector>
#include <string>

namespace PROJECT_EULER {
	enum WINNER_TYPE {
		NONE            = 0x0000,
		HIGH_CARD       = 0x0001,
		ONE_PAIR        = 0x0002,
		TWO_PAIRS       = 0x0003,
		THREE_OF_A_KIND = 0x0004,
		STRAIGHT        = 0x0005,
		FLUSH           = 0x0006,
		FULL_HOUSE      = 0x0007,
		FOUR_OF_A_KIND  = 0x0008,
		STRAIGHT_FLUSH  = 0x0009,
		ROYAL_FLUSH     = 0x000A,
	};

	struct Hand {
		std::vector<int> value;
		std::string type;
	};

	struct Rank {
		WINNER_TYPE type;
		int value;
		char card;

		Rank() {
			type = NONE;
			value = 0;
			card = ' ';
		}
	};
	
	
	class Poker {
	public:
		Poker();
		~Poker();

		int Winner(const std::string& hands);

	private:
		void m_parseHands(const std::string& hands,
						  Hand& player1, Hand& player2);

		int m_findWinner(const Hand& player1, const Hand& Player2);
		void m_getPlayerRanking(const Hand& player, Rank& rank);
		int m_getCardValue(const char card);

		bool m_allCardsSame(const std::string& type);
		
		bool m_royalFlush(const Hand& player);
		bool m_straightFlush(const Hand& player);
		bool m_fourOfAKind(const Hand& player, int& result);
		bool m_fullHouse(const Hand& player, int& result);
		bool m_flush(const Hand& player);
		bool m_straight(const Hand& player);
		bool m_threeOfAKind(const Hand& player, int& result);
		bool m_twoPairs(const Hand& player);
		bool m_onePair(const Hand& player, int& result);
		int m_highCard(const Hand& player);

		int m_calculateWinner(const Rank& rank1, const Rank& rank2);
	};
};

#endif // PROJECT_EULER_PROBLEM_54_POKER_H_
