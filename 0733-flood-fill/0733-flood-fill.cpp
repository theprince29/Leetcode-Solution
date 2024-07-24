

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& result,
             vector<vector<int>>& image, int newColor, int deltaRow[], int deltaCol[],
             int initialColor) {
        result[row][col] = newColor; 
        int numRows = image.size();
        int numCols = image[0].size(); 
        for(int i = 0; i < 4; i++) {
            int newRow = row + deltaRow[i]; 
            int newCol = col + deltaCol[i]; 
            if(newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && 
               image[newRow][newCol] == initialColor && result[newRow][newCol] != newColor) {
                dfs(newRow, newCol, result, image, newColor, deltaRow, deltaCol, initialColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int startRow, int startCol, int newColor) {
        int initialColor = image[startRow][startCol]; 
        vector<vector<int>> result = image; 
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1}; 
        dfs(startRow, startCol, result, image, newColor, deltaRow, deltaCol, initialColor); 
        return result; 
    }
};