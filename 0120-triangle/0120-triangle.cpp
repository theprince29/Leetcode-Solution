class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
        if (i == triangle.size() - 1) return triangle[i][j]; 
        
        if (memo[i][j] != -1) return memo[i][j];  
        
        int down = dfs(i + 1, j, triangle, memo);
        int downRight = dfs(i + 1, j + 1, triangle, memo);
        
        return memo[i][j] = triangle[i][j] + min(down, downRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); 
        return dfs(0, 0, triangle, memo); 
    }
};