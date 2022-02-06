class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        to = vector<vector<int>>(numCourses, vector<int>());
        inDeg = vector<int>(numCourses, 0);
        for (vector<int>& pre: prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            to[bi].push_back(ai);
            inDeg[ai]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (inDeg[i] == 0) q.push(i);
        vector<int> lessons;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x);
            for (int y : to[x]) {
                inDeg[y]--;
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
        return lessons.size() == numCourses;
    }

private:
    vector<vector<int>> to;
    vector<int> inDeg;
};
