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
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool last_word = false;
        for (string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
            if (rit == s.rbegin() && *rit == ' ') { 
                continue;
            }
            else if (rit == s.rbegin() && *rit != ' ') { 
                ans += 1;
                last_word = true;
            }
            else if (*rit == ' ' && !last_word) { 
                continue;
            }
            else if (*rit == ' ' && last_word) {
                break;
            }
            else {
                ans += 1;
                last_word = true;
            }
        }

        return ans;
    }
};

int main() {
    Solution mySolution;
    string s = "  aa  ";
    int ans = mySolution.lengthOfLastWord(s);
    cout << ans << endl;
    return 0;
}
