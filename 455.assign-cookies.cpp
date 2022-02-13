#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int child : g) {
            while (j < s.size() && s[j] < child) j++;
            if (j < s.size()) { ans++; j++; }
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    int ans = mySolution.findContentChildren(g, s);
    cout << ans << endl;
    return 0;
}
