/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
*/
#include <vector>
using std::vector;

//time limit exceded
class firstSolution {
public:
    int tribonacci(int n) {
        if (n < 0)
            return 0;
        else if (n == 0) 
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 1;
        else 
            return tribonacci(n - 3) +  tribonacci(n - 2) + tribonacci(n - 1);
        
    }
};
//stack overflow
class secondSolution {
public:
    int tribonacci(int n) {
        vector<long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; ++i)
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]);
        return dp[n];
    }
};

class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1, tmp;
        
        for (int i = 3; i <= n; ++i){
            tmp = third;
            third = first + second + third;
            first = second;
            second = tmp;
        }
        return third;
    }
};