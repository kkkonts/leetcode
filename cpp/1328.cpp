/*
Given a palindromic string of lowercase English letters palindrome, 
replace exactly one character with any lowercase English letter so that 
the resulting string is not a palindrome and that it is the lexicographically smallest one possible.
Return the resulting string. 
If there is no way to replace a character to make it not a palindrome, return an empty string.
A string a is lexicographically smaller than a string b (of the same length)
if in the first position where a and b differ, a has a character strictly smaller
than the corresponding character in b. For example, "abcc" is lexicographically smaller 
than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.*/
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

class PerfectSolution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if(n == 1) return "";
        int j = n - 1;
        int flag = 0;
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != 'a'){
                s[i] = 'a';
                flag = 1;
                break;
            }
            j--;
        }
        if (flag==0) s[n-1] = 'b';
        return s;
    }
};

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i = 0, size = palindrome.size();
        char chr = 'a';
        if (size == 1)
            return string("");

        while (chr == 'a' && i < size) {
            chr = palindrome[i];
            i++;
        }

        if (i == size || (size % 2 == 1 && i == size / 2 + size % 2))
            palindrome[size - 1] = 'b';
        else
            palindrome[i - 1] = 'a';
        return palindrome;
    }
};

int main() {
    string palindrome;
    string result;
    cin >> palindrome;

    Solution s;
    s.breakPalindrome(palindrome);




    return 0;
}



