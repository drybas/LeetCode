#include <vector>
#include <limits>

using namespace std;

// 122. Best Time to Buy and Sell Stock II

int maxProfit(std::vector<int>& prices) {

    auto profit = 0;
    auto cur_sell = 0;
    auto cur_buy = std::numeric_limits<int>::max();
    bool want_buy = true;
    for (auto i = 0; i < prices.size(); i++)
    {
        if (want_buy && prices[i] <= cur_buy)
        {
            cur_buy = prices[i];
            cur_sell = 0;
            continue;
        }

        want_buy = false;
        if ((prices[i]) >= cur_sell)
        {
            cur_sell = prices[i];
        }
        else if (cur_sell - cur_buy > 0)
        {
            profit += cur_sell - cur_buy;
            cur_sell = 0;
            want_buy = true;
            cur_buy = prices[i];
        }
    }

    if (want_buy == false && cur_sell - cur_buy > 0)
    {
        profit += cur_sell - cur_buy;
    }

    return profit;
}
