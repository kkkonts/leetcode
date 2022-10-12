/*Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
If it is impossible to form any triangle of a non-zero area, return 0.*/
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){ return x > y;});
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i){
            if (nums[i] < nums[i + 1] + nums[i + 2]) 
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        return 0;
    }
};