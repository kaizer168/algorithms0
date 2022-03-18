#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    int x;
    int towerHeight = 0;
    int towerHeightTmp = 0;
    vector<int> tower = {};
    vector<vector<int>> group = {};
    int ans = 0;
    int j = 0;

    cin >> N;

    group = vector<vector<int>>(N, vector<int>());

    for (int i = 0; i < N; i++) {
        cin >> x;
        tower.push_back(x);
    }

    for (int i = 0; i < tower.size(); i++) {
        if (tower[i] >= towerHeight) {
            towerHeight = tower[i];
            group[j].push_back(tower[i]);
            j++;
        }
        else {
            towerHeightTmp += tower[i];
            if (towerHeightTmp < towerHeight) {
                group[j].push_back(tower[i]);
            }
            else {
                group[j].push_back(tower[i]);
                j++;
            }
        }
    }

    for (int m = 0; m < group.size(); m++) {
        for (int n = 0; n < group[m].size(); n++) {
        }
    }

    ans = N - j;
    cout << ans << endl;

    return 0;
}

