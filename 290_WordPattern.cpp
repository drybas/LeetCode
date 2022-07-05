
#include <iostream>
#include <map>
#include <string>

using namespace std;

// 290. Word Pattern

bool wordPattern(string pattern, string str) {
    std::map<char, string> m;
    std::map<string, char> v;
    auto last_p = 0;
    auto p = str.find(' ');
    auto word = str.substr(last_p, p);
    for (auto i : pattern) {
        if (word.empty())
            return false;

        auto r = m.find(i);
        if (r != m.end() && r->second != word) {
            return false;
        }
        else {
            auto rv = v.find(word);
            if (rv != v.end() && rv->second != i)
                return false;
        }

        m.insert(make_pair(i, word));
        v.insert(make_pair(word, i));

        last_p = p;
        if (last_p > 0) {
            p = str.find(' ', last_p + 1);
            word = str.substr(last_p + 1, p - last_p - 1);
        } 
        else {
            word = "";
        }

    }
    return word.size() == 0;
}

int main() {
    string pattern0 = "abba", str0 = "dog cat cat dog";
    auto r = wordPattern(pattern0, str0);
    std::cout << r << "\r\n";
    
    string pattern = "abba", str = "dog dog dog dog";
    r = wordPattern(pattern, str);
    std::cout << r << "\r\n";
   
    string pattern1 = "aa", str1 = "aa";
    r = wordPattern(pattern1, str1);
    std::cout << r << "\r\n";

    return 0;
}
