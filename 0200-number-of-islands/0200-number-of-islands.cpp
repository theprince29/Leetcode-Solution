class Solution {

    private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});

        while (!q.empty())
        {
            int rows = q.front().first;
            int cols = q.front().second;
            q.pop();

            int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (int i = 0; i < 4; ++i) {
                int nrow = rows + directions[i][0];
                int ncol = cols + directions[i][1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }




public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        int count =0;
        for(int i=0; i<n;i++)
        {
            for(int j =0 ; j<m ;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};