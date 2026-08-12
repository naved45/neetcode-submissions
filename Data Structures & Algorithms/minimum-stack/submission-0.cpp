#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;       // main stack
    stack<int> minSt;    // stack to track minimums

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        // push to minSt if empty or val <= current min
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
