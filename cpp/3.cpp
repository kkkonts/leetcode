//Given a string s, find the length of the longest substring without repeating characters.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int chars = 0;
        for (auto c : s) {
            if (m[c] == 0) chars++; //number of unique elements
            m[c] = 1;
        }

        size_t start = 0, end = 0, maxLen = 0, cur = 0;
        size_t size = s.size();

        while (end < size) {
            if (m[s[end]] == 1) {
                cur++;
                m[s[end]] = 0;
            }

            else if (m[s[end]] == 0) {
                while (start <= end) {
                    if (s[start] == s[end]) {
                        start++;
                        cur = end - start + 1;
                        cout << start << end << endl;
                        break;
                    }
                    m[s[start]] = 1;
                    start++;
                }
            }

            end++;
            cout << "cur "<< cur << endl;
            maxLen = maxLen < cur ? cur : maxLen;
        }
        return maxLen;
    }
};