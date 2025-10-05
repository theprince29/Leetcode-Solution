class Solution {
private:
    int m, n;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i,
             int j) {
        visited[i][j] = true;
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if (visited[x][y])
                continue;
            if (heights[x][y] < heights[i][j])
                continue;
            dfs(heights, visited, x, y);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0);
        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j);

        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1);
        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};