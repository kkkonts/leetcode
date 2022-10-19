/*The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
Given a positive integer n, return the nth term of the count-and-say sequence.
*/
#include <string>
#include <iostream>

using namespace std;
using std::string;



class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) 
            return "1";
        else if (n == 2)
            return "11";
        else {
            string res, str = countAndSay(n - 1);
            char cur, next, cnt = 0;                //current and next after current element of str
                                                    // and counter of the same numbers
            
            for (int i = 0; i < str.size(); ++i){
                cur = str[i];
                if (i == str.size() - 1) {          // if it's the last one
                     //res.push_back(++cnt);
                     //res.push_back(cur); 
                    res += to_string(++cnt); 
                    res += cur; 
                } else {                            //if not the last
                     next = str[i + 1];
                     if (next != cur) {             //and if it's last of equals 
                         res += to_string(++cnt); 
                         res += cur; 
                         cnt = 0;
                     }
                     else 
                         ++cnt;
                 } 
            }
            return res;
        }
    }
};

int main() {
    Solution s;
    std::cout << s.countAndSay(2);

    return 0;
}