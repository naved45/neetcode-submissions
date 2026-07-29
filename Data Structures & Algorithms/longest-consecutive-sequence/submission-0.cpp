#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        
        for (int num : s) {
            // Only start counting if 'num' is the beginning of a sequence
            if (!s.count(num - 1)) {
                int currentNum = num;
                int streak = 1;
                
                while (s.count(currentNum + 1)) {
                    currentNum++;
                    streak++;
                }
                
                longest = max(longest, streak);
            }
        }
        
        return longest;
    }
};
