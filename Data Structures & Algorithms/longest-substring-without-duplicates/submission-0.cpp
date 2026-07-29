class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1); // store last index of each character
        int maxLen = 0, start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // if character already seen, move start
            if (index[s[i]] >= start) {
                start = index[s[i]] + 1;
            }
            index[s[i]] = i; // update last seen index
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};
