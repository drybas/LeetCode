
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 524. Longest Word in Dictionary through Deleting 

bool substr(const std::string& x, const std::string& str) {
    auto j = 0;
    for (auto i = 0; i < x.size() && j < str.size(); i++) {
        if (x[i] == str[j]) {
            j++;
        }
    }
    return j == str.size();
}

string findLongestWord(string s, vector<string>& d) {
    std::string max_str;
    for (auto& i : d) {
        if (substr(s, i)) {
            if (max_str.size() < i.size()) {
                max_str = i;
            }
            else if (max_str.size() == i.size() && max_str.compare(i) > 0) {
                max_str = i;
            }
        }
    }
    return max_str;
}

int main()
{

    std::string s = "abpcplea";
    {
        std::vector<std::string> d{ "ale", "apple", "monkey", "plea" };
        auto r = findLongestWord(s, d);
        std::cout << "[" << r << "]\r\n";
    }

    {
        std::vector<std::string> d{ "a", "b", "c" };
        auto r = findLongestWord(s, d);
        std::cout << "[" << r << "]\r\n";
    }
} 