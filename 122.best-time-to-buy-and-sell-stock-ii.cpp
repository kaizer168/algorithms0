#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    vector<int> prices = {7,1,5,3,6,4};
    int ans = mySolution.maxProfit(prices);
    cout << ans << endl;
    return 0;
}
