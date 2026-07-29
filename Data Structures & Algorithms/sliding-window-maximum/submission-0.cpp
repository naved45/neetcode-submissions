class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of useful elements
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove smaller elements (they’ll never be max if current is bigger)
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Add max of current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
