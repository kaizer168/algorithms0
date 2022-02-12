#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int ans = 0;
       sort(coins.begin(), coins.end(), greater<int>());
       auto ptr = coins.begin();
       while (amount && ptr != coins.end()) {
           if (amount >= (*ptr)) {
               ans += (amount / (*ptr));
               amount %= (*ptr);
           }
           ptr++;
       }
       return amount ? -1 : ans;
    }
};

int main() {
    Solution mySolution;
    vector<int> coins = {1,2,5};
    int ans = mySolution.coinChange(coins, 11);
    cout << ans << endl;
    return 0;
}
