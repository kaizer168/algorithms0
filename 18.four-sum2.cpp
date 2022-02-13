#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        if (n == 0) return {};
        recur(nums, 0);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j=j+4) {
                if (ans[i][j] + ans[i][j+1] + ans[i][j+2] + ans[i][j+3] == target) {
                    final_ans.push_back(ans[i]);
                }
            }
        }

        unique = true;
        for (int m = 0; m < final_ans.size(); m++) {
            for (int n = 0; n < final_ans2.size(); n++) {
                if (final_ans[m] == final_ans2[n]) {
                    unique = false;
                }
            }
            if (unique == true) {
                final_ans2.push_back(final_ans[m]);
            }
            unique = true;
        }

        return final_ans2;
    }
    
private:
    void recur(vector<int>& nums, int i) {
        if (chosen.size() > k || chosen.size() + (n - i) < k) return;
        if (i == n) {            
            ans.push_back(chosen);
            return;
        }

        recur(nums, i + 1);
        chosen.push_back(nums[i]);
        recur(nums, i + 1);
        chosen.pop_back();
    }

    int n;
    int k = 4;
    bool unique;
    vector<int> chosen;
    vector<vector<int>> ans;
    vector<vector<int>> final_ans;
    vector<vector<int>> final_ans2;
};

int main() {
    Solution mySolution;
    //vector<int> nums = {-5, 5, 4, -3, 0, 0, 4, -2};
    //vector<int> nums = {-500,-481,-480,-469,-437,-423,-408,-403,-397,-381,-379,-377,-353,-347,-337,-327,-313,-307,-299,-278,-265,-258,-235,-227,-225,-193,-192,-177,-176,-173,-170,-164,-162,-157,-147,-118,-115,-83,-64,-46,-36,-35,-11,0,0,33,40,51,54,74,93,101,104,105,112,112,116,129,133,146,152,157,158,166,177,183,186,220,263,273,320,328,332,356,357,363,372,397,399,420,422,429,433,451,464,484,485,498,499};
    //2139
    vector<int> nums = {-497,-494,-484,-477,-453,-453,-444,-442,-428,-420,-401,-393,-392,-381,-357,-357,-327,-323,-306,-285,-284,-263,-262,-254,-243,-234,-208,-170,-166,-162,-158,-136,-133,-130,-119,-114,-101,-100,-86,-66,-65,-6,1,3,4,11,69,77,78,107,108,108,121,123,136,137,151,153,155,166,170,175,179,211,230,251,255,266,288,306,308,310,314,321,322,331,333,334,347,349,356,357,360,361,361,367,375,378,387,387,408,414,421,435,439,440,441,470,492};
    //1682
    vector<vector<int>> ans = mySolution.fourSum(nums, 1682);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
