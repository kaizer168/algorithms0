class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = 0;
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            n = max(n, max(x, y));
        }
        to = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1]; 
            to[x].push_back(y);
            to[y].push_back(x);      
            hasCycle = false;
            for (int i = 1; i <= n; i++) visited[i] = false;
            dfs(x, 0);
            if (hasCycle) return edge;
        }
        return {};
    }

private:
    void dfs(int x, int fa) {
        visited[x] = true;
        for (int y : to[x]) {
            if (y == fa) continue;
            if (!visited[y]) dfs(y, x);
            else hasCycle = true;
        }
    }
    int n;
    vector<vector<int>> to;
    vector<bool> visited;
    bool hasCycle;
};
