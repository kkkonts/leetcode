/*Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int minLen = INT_MAX, start = 0, end = 0,
                curSum = 0, curLen = 0, size = v.size();

        while (end < size) {
            curSum += v[end];
            curLen++;

            if (curSum >= target){
                while (start < end) {
                    if ((curSum - v[start]) >= target) {
                        curSum -= v[start];
                        start++;
                        curLen--;
                    }
                    else
                        break;
                }
            }

            cout << start << end << curSum << " " << curLen << endl;

            minLen = ((minLen < curLen) || (curSum < target)) ? minLen : curLen;
            end++;
        }

        minLen = (minLen == INT_MAX) ? 0 : minLen;

        return minLen;
    }
};