#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (sum < target) {
                left++; // move left pointer to increase sum
            } else {
                right--; // move right pointer to decrease sum
            }
        }
        
        return {}; // should never reach here since one solution always exists
    }
};
