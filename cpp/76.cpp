class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> ch(127, 0);

        for (auto sym : t) ch[sym]++;

        size_t counter = t.size(), start_res = 0, start = 0, end = 0,
                head = 0, min_len = INT_MAX, size = s.size(), k = 0;

        while (end < size) {
            if (ch[s[end]] > 0) {
                counter--;
            }
            ch[s[end]]--;

            while (counter == 0) {
                if ((end - start + 1) < min_len){
                    min_len = end - start + 1;
                    start_res = start;
                }

                ch[s[start]]++;

                if (ch[s[start]] > 0)
                    counter++;
                start++;
            }
            end++;
        }

        return  min_len == INT_MAX ?
                "" : s.substr(start_res, min_len);
    }

};