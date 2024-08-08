class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});

        int totalCells = rows * cols;
        int x = rStart, y = cStart; 
        int dir = 0; 
        int steps = 1; 

        vector<int> directions = {0, 1, 0, -1, 0};

        while (ans.size() < totalCells) {
            for (int i = 0; i < 2; ++i) { 
                for (int j = 0; j < steps; ++j) {
                    
                    x += directions[dir];
                    y += directions[dir + 1];

                    
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        ans.push_back({x, y});
                    }
                }
                
                dir = (dir + 1) % 4;
            }
            
            steps++;
        }

        return ans;
    }
};