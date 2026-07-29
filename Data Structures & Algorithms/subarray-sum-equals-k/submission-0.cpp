#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1; // base case: empty prefix

        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            // check if there exists a prefix with sum-k
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};
