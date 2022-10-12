/*
Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:

nums[a] + nums[b] + nums[c] == nums[d], and
a < b < c < d
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::sort;
using std::map;
using std::string;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2; 




        
    }
};