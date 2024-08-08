class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val =1;
        while (top <= bottom && left <= right) {
            
            for (int j = left; j <= right; ++j) {
                result[top][j] = val;
                val++;
            }
            ++top;
            
            
            for (int i = top; i <= bottom; ++i) {
                result[i][right] = val;
                val++;
            }
            --right;
            
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result[bottom][j]=val;
                    val++;
                }
                --bottom;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result[i][left] = val;
                    val++;
                }
                ++left;
            }
        }
        
        return result;
    }
};