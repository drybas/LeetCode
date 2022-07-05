// LHS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

// 594. Longest Harmonious Subsequence

int findLHS(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    auto s = nums.begin();
    auto i = nums.begin();
    i++;
    int delta = 0;
    for (; i != nums.end(); i++)
    {
        if (*i == *s) {
            continue;
        }
        if (*i - *s == 1) {
            auto d = std::distance(s, i);
            delta = std::max(delta, d + 1);
        }
        else {
            for (s; s != i; s++)
                if (*i - *s == 1) {
                    delta = std::max(delta, std::distance(s, i) + 1);
                    break;
                }
        }
    }

    return delta;
}

int main()
{
    {
        std::vector<int> v = { 1, 3, 2, 2, 5, 2, 3, 7 };
        std::cout << findLHS(v) << "\r\n";
    }
    {
        std::vector<int> v = { 1, 2, 3, 4 };
        std::cout << findLHS(v) << "\r\n";
    }
    {
        std::vector<int> v = { 1, 1, 1, 1 };
        std::cout << findLHS(v) << "\r\n";
    }
    {
        std::vector<int> v = { 1, 2, 2, 1 };
        std::cout << findLHS(v) << "\r\n";
    }
}

