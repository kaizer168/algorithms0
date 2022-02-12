#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        coins[5] = coins[10] = coins[20] = 0;
        for (int bill : bills) {
            coins[bill]++;
            if (!exchange(bill - 5)) return false;
        }
        return true;
    }

private:
    bool exchange(int amount) {
        for (int x : {20, 10, 5}) {
            while (amount >= x && coins[x] > 0) {
                amount -= x;
                coins[x]--;
            }
        }
        return amount == 0;
    }

    unordered_map<int,int> coins;
};

int main() {
    Solution mySolution;
    vector<int> bills = {5,5,5,10,20};
    bool ans = mySolution.lemonadeChange(bills);
    cout << ans << endl;
    return 0;
}
