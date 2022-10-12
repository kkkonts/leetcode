/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;

class perfectSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res{2};
        int search;
        bool flag = 1;
        
        for (int i = 0; i < nums.size() && flag; ++i) {
            search = target - nums[i];
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] == search) {
                    res[1] = j;
                    res[0] = i;
                    flag = 0;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}



