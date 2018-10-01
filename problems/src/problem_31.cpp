#include "problem_31.h"
#include <cstdio>
#include <chrono>

const std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

project_euler::problems::Problem_31::Problem_31() {}

project_euler::problems::Problem_31::~Problem_31() {}

void project_euler::problems::Problem_31::coin_sums() const {
    int amount = 200;
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    printf("Coin Sums == [%d]\n", m_coin_sums_iterative(amount));
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start).count());
    printf("--------------------------------------------------\n");

    printf("----------------- Recursive Algorithm ------------\n");
    start = clock::now();
    printf("Coin Sums == [%d]\n", m_coin_sums_recursive(amount, coins.size() - 1));
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start).count());
    printf("--------------------------------------------------\n");

    printf("----------------- DP Algorithm -------------------\n");
    start = clock::now();
    std::vector< std::vector<int> > memo;
    for (int i = 0; i <= amount; ++i) {
        std::vector<int> m;
        for (int j = 0; j < static_cast<int>(coins.size()); ++j)
            m.push_back(0);
        memo.push_back(m);
    }
    printf("Coin Sums == [%d]\n", m_coin_sums_dp(amount, coins.size() - 1, memo));
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start).count());
    printf("--------------------------------------------------\n");

    printf("-------------- DP Bottom UP Algorithm ------------\n");
    start = clock::now();
    printf("Coin Sums == [%d]\n", m_coin_sums_dp_bottom_up(amount));
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start).count());
    printf("--------------------------------------------------\n");
}

int project_euler::problems::Problem_31::m_coin_sums_iterative(int amount) const {
    int sums = 0;
    for (int a = 0; a <= amount; a += coins[0])
        for (int b = 0; b <= amount; b += coins[1])
            for (int c = 0; c <= amount; c += coins[2])
                for (int d = 0; d <= amount; d += coins[3])
                    for (int e = 0; e <= amount; e += coins[4])
                        for (int f = 0; f <= amount; f += coins[5])
                            for (int g = 0; g <= amount; g += coins[6])
                                for (int h = 0; h <= amount; h += coins[7])
                                    if (amount == a + b + c + d + e + f + g + h)
                                        ++sums;

    return sums;
}

int project_euler::problems::Problem_31::m_coin_sums_recursive(int amount, int pos) const {
    if (pos <= 0)
        return 1;

    int sums = 0;
    while (amount >= 0) {
        sums += m_coin_sums_recursive(amount, pos - 1);
        amount -= coins[pos];
    }

    return sums;
}

int project_euler::problems::Problem_31::m_coin_sums_dp(int amount, int pos,
                                                        std::vector< std::vector<int> >& memo) const {
    int amt = amount;
    if (pos <= 0)
        return 1;

    if (memo[amt][pos])
        return memo[amt][pos];

    int sums = 0;
    while (amount >= 0) {
        sums += m_coin_sums_dp(amount, pos - 1, memo);
        amount -= coins[pos];
    }

    memo[amt][pos] = sums;
    return sums;
}

int project_euler::problems::Problem_31::m_coin_sums_dp_bottom_up(int amount) const {
    std::vector<int> sums;
    for (int i = 0; i <= amount; ++i)
        sums.push_back(0);

    sums[0] = 1;
    for (int i = 0; i < static_cast<int>(coins.size()); ++i)
        for (int j = coins[i]; j <= amount; ++j)
            sums[j] += sums[j - coins[i]];

    return sums[amount];
}
