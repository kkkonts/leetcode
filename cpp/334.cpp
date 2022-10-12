#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::sort;
using std::map;

class PerfectSolution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums) {
            if (x <= c1) {
                c1 = x;           
            } else if (x <= c2) { 
                c2 = x;           
            } else {              
                return true;      
            }
        }
    return false;
    }
};