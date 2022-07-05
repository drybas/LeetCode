#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<size_t> tmp(strs.size());
        std::unordered_map<std::string, std::pair<size_t, size_t>> dict;
        int inserted = 0;
        for (auto i = 0; i < strs.size(); i++) {
            std::string fp(strs[i]);
            std::sort(fp.begin(), fp.end());

            auto v = dict.find(fp);
            if (v != dict.end()) {
                v->second.second++;
                tmp[i] = v->second.first;
            }
            else {
                dict.insert({ fp,{ inserted, 1 } });
                tmp[i] = inserted;
                inserted++;
            }
        }

        std::vector<std::vector<string>> result(inserted);
        for (auto i = 0; i < tmp.size(); i++) {
            result[tmp[i]].push_back(strs[i]);
        }
        return result;
    }
};