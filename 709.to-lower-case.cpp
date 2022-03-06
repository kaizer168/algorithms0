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
    string toLowerCase(string s) {
        string ans;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            if (*it >= 'A' && *it <= 'Z') ans += *it - 'A' + 'a';
            else ans += *it;
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    string s = "al&phaBET";
    string ans = mySolution.toLowerCase(s);
    cout << ans << endl;
    return 0;
}
