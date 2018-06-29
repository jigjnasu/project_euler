/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 25th, 2016
*/

#include "Problem_54.h"
#include "Poker.h"
#include <fstream>

// Constant values to hold 
const std::string CARD_TYPE = "CDHS";
const std::string CARD_VALUE = "23456789TJQKA";

namespace pp = project_euler::problems;

pp::Problem_54::Problem_54() {}

pp::Problem_54::~Problem_54() {}

void pp::Problem_54::count_player_wins(int player) const {
    Poker poker;
    int wins_count = 0;
    std::vector< std::vector<Card> > A;
    std::vector< std::vector<Card> > B;
	
    if (m_read_data("../data/poker.txt", A, B)) {
        for (std::size_t i = 0; i < A.size(); ++i) {
            if (player == poker.Winner(A[i], B[i])) {
                ++wins_count;
            }
        }
    }

    printf("-------------------------------------------------------------------------\n");
    printf("Player [%d] wins == [%d] mathces out of 1000\n", player, wins_count);
    printf("-------------------------------------------------------------------------\n");    
}

bool pp::Problem_54::m_read_data(const std::string& file,
                                 std::vector< std::vector<Card> >& A,
                                 std::vector< std::vector<Card> >& B)  const {
    std::ifstream ifs(file.c_str());
    bool result = true;
    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            std::vector<Card> player1;
            std::vector<Card> player2;

            int index = -1;
            for (int i = 0; i < 10; ++i) {
                int pos = line.find(" ", index + 1);
                const std::string data = line.substr(index + 1, 2);
                Card C(data[1], CARD_VALUE.find(data[0]) + 2);

                if (i < 5)
                    player1.push_back(C);
                else
                    player2.push_back(C);
                index = pos;
            }
            A.push_back(player1);
            B.push_back(player2);
        }
			
    } else {
        printf("Error: There is an error while [%s] file\n", file.c_str());
        result = false;
    }
	
    return result;
}
