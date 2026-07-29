#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // add current subset
        
        for(int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);          // choose element
            backtrack(nums, i+1, current, result); // explore further
            current.pop_back();                  // undo choice
        }
    }
};
