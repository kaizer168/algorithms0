class Solution {
public:
        int treeDiameter(vector<vector<int>>& edges) {
            int n = 0;
	    for(vector<int>& edge : edges) {
                int x = edge[0];
		int y = edge[1];
		n = max(n, max(x, y));
	    }
	    n++;
	    for (int i = 0; i < n; i++) to.push_back({});
	    for(vector<int>& edge : edges) {
                int x = edge[0];
		int y = edge[1];
		to[x].push_back(y);
		to[y].push_back(x);
	    }
	    int p = findFarthest(0).first;
	    return findFarthest(p).second;
	}

private:
	vector<vector<int>> to;
	pair<int, int> findFarthest(int start) {
            vector<int> depth(n, -1);
            queue<int> q;
	    q.push(start);
	    depth[start] = 0;
	    while (!q.empty()) {
                int x = q.front();
		q.pop();
		for (int y : to[x]) {
                    if (depth[y] != -1) continue;
		    depth[y] = depth[x] + 1;
		    q.push(y);
		}
	    }
	    int ans = start;
	    for (int i = 0; i < n; i++)
                if (depth[i] = depth[ans]) ans = i;
	    return {ans, depth[ans]};
	}
}
