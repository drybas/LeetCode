
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// 949. Largest Time for Given Digits

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        std::vector<int> maxx{ 2, 3, 5, 9 };
        auto out = test(A, maxx);

        std::vector<int> maxx2{ 1, 9, 5, 9 };
        auto out2 = test(A, maxx2);
        return ((out > out2) ? out : out2);
    }

    string test(vector<int> A, vector<int> maxx) {
        stringstream ss;
        for (auto m : maxx) {
            auto p = mfind(std::begin(A), std::end(A), m);
            if (p == std::end(A))
                return "";
            ss << *p;
            A.erase(p);
            if (A.size() == 2)
                ss << ":";
        }
        return ss.str();
    }

    std::vector<int>::iterator mfind(std::vector<int>::iterator b, std::vector<int>::iterator e, int m) {
        auto p = e;
        for (auto i = b; i != e; i++) {
            if (p == e && *i <= m) {
                p = i;
            }
            else if (p != e && *i > * p && *i <= m) {
                p = i;
            }
        }
        return p;
    }

};