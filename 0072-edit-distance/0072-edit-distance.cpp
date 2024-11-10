#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        if (i == word1.size()) return word2.size() - j;
        if (j == word2.size()) return word1.size() - i;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp);
        } else {
            int insertOp = 1 + solve(word1, word2, i, j + 1, dp);       // Insert in word1
            int deleteOp = 1 + solve(word1, word2, i + 1, j, dp);       // Delete from word1
            int replaceOp = 1 + solve(word1, word2, i + 1, j + 1, dp);  // Replace in word1
            return dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
