class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();  // Get the dimensions of the grid
    int total_operations = 0;

    // Iterate over each column
    for (int j = 0; j < n; j++) {
        // Iterate over each row except the last
        for (int i = 0; i < m - 1; i++) {
            // If the next row's value is less than or equal to the current row's value
            if (grid[i + 1][j] <= grid[i][j]) {
                // Calculate the operations needed
                int operations = grid[i][j] - grid[i + 1][j] + 1;
                total_operations += operations;
                // Increment the value to make it strictly greater
                grid[i + 1][j] += operations;
            }
        }
    }

    return total_operations;
}

};