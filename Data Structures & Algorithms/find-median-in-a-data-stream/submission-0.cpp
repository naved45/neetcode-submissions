#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    // Max-heap for the smaller half
    priority_queue<int> left;
    // Min-heap for the larger half
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to max-heap
        left.push(num);

        // Step 2: Balance by moving top of left to right
        right.push(left.top());
        left.pop();

        // Step 3: Ensure left has equal or one more element than right
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top(); // odd count
        } else {
            return (left.top() + right.top()) / 2.0; // even count
        }
    }
};
