class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxCount = 0, result = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            // If more than k replacements needed, shrink window
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
