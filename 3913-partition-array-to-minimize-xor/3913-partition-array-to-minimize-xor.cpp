#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixor(n + 1, 0);

        
        for (int i = 1; i <= n; i++) {
            prefixor[i] = prefixor[i - 1] ^ nums[i - 1];
        }

       
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;

        
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefixor[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= min(k, i); j++) {
                for (int t = 1; t < i; t++) {
                    if (dp[t][j - 1] != INT_MAX) {
                        int currXor = prefixor[i] ^ prefixor[t];
                        dp[i][j] = min(dp[i][j], max(dp[t][j - 1], currXor));
                    }
                }
            }
        }

        return dp[n][k];
    }
};
