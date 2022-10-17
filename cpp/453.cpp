#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), dif;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n/2 + 1; i++) {
            dif = nums[n - i - 1] - nums[0];
            for (int j = 0; i < n; i++) {
                if (j != (dif < 0 ? i : (n - 1 - i)))
                    nums[j] += dif;
            }
        }

    }
};

//time limit exceeded
class FirstSolution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), dif, moves = 0;
        sort(nums.begin(), nums.end());
        //int min = nums[distance(nums.begin(), min_element(nums.begin(), nums.end()))], 
            //maxi = distance(nums.begin(), max_element(nums.begin(), nums.end())),
            //max = nums[maxi];
        
        while (nums[n - 1] != nums[0]){
            dif = nums[n - 1] - nums[0];
            moves += dif;
            for (int i = 0; i < n - 1; ++i) {
                    nums[i] += dif;
            }
            sort(nums.begin(), nums.end());
            //min = nums[distance(nums.begin(), min_element(nums.begin(), nums.end()))]; 
            //maxi = distance(nums.begin(), max_element(nums.begin(), nums.end()));
            //max = nums[maxi];
        }
        return moves;
    }
};