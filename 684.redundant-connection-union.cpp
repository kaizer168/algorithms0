#include <iostream>
#include <vector>
using namespace std;

class UF {
public:
    UF(int n) {
        father = vector<int>(n + 1, 0);
        for (int i = 0; i < father.size(); ++i) {
            father[i] = i;
        }
    }

    int Find(int u) {
        if (u == father[u]) {
            return u;
        }
        else {
            father[u] = Find(father[u]);
            return father[u];
        }
    }

    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        if (fa != fb) {
            father[fa] = fb;
        }
    }

private:
    vector<int> father;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(edges.size());

        for (const auto& edge : edges) {
            fa = uf.Find(edge[0]);
            fb = uf.Find(edge[1]);
            if (fa != fb) {
                uf.Union(edge[0], edge[1]);
            }
            else {
                return edge;
            }
        }
        return {};
    }

private:
    int fa;
    int fb;
};

int main() {
    Solution mySolution;
    vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    vector<int> ans = mySolution.findRedundantConnection(edges);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
