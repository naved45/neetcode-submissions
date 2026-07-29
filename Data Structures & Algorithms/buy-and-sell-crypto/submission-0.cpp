#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);              // update minimum price
            maxProfit = max(maxProfit, price - minPrice); // update max profit
        }

        return maxProfit;
    }
};
