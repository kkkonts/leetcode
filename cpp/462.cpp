#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        s  int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            steps += nums[n-1-i] - nums[i]; //Adding difference
        }
        return steps;
        
    }
};

/// O(n^2) - just to work out this problem 
class SlowSolution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int min = nums[0], 
            max = nums[nums.size() - 1];
        long min_diff = 1e8,     
             sum_diff = 0;
        
        //num - possible element to equalize others
        for (int num = min; num <= max; ++num) { 
            for (int j = 0; j < nums.size(); ++j) {
                sum_diff += abs(static_cast<long>(num - nums[j]));
            }
            if (sum_diff < min_diff) 
                min_diff = sum_diff;
            sum_diff = 0;
        }
        return static_cast<int>(min_diff);
        
    }
};