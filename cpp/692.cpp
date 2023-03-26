#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        vector<string> res(k);
        
        for (int i = 0; i < words.size(); ++i) {
            if (mp.count(words[i]) == 0)
                mp[words[i]] = 1;
            else
                ++mp[words[i]];
        }
        
        bool cmp = [](pair<string, int> const &a, pair<string, int> const &b) { 
            return a.second != b.second ?  a.second < b.second : a.first < b.first;
        };
        
        sort(mp.begin(), mp.end(), cmp);
        
        map<string, int>::iterator it = mp.begin();
        
        for (int i = 0; i < k && it != mp.end(); ++i, ++it) { 
            res.push_back(it->first);
        }   
        return res;
    }
};