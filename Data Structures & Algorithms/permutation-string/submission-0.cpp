#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequency of s1
        for (char c : s1) freq1[c - 'a']++;

        // Sliding window of size s1.length()
        for (int i = 0; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;

            // Maintain window size
            if (i >= s1.size()) {
                freq2[s2[i - s1.size()] - 'a']--;
            }

            // Compare frequency arrays
            if (freq1 == freq2) return true;
        }

        return false;
    }
};
