#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewels_set;
        int ans = 0;
        for (string::iterator it = jewels.begin(); it != jewels.end(); it++) {
            jewels_set.insert(*it);
        }
        for (string::iterator it = stones.begin(); it != stones.end(); it++) {
            if (jewels_set.find(*it) != jewels_set.end()) ans++;
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    string jewels = "aA";
    string stones = "aAAbbbb";
    int ans = mySolution.numJewelsInStones(jewels, stones);
    cout << ans << endl;
    return 0;
}
