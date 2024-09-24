class Solution {
private:

  

    int fun(int ind, int target ,   vector<vector<int>> &dp) {
        
        if (target == 0) return 0; 

        if (ind <= 0 || target < 0) return INT_MAX;  

        if (dp[ind][target] != -1) return dp[ind][target];

        
        int nottake = fun(ind - 1, target ,dp);

        
        int take = INT_MAX;

        if (ind * ind <= target) {

            int result = fun(ind, target - (ind * ind),dp); 

            if (result != INT_MAX) {
                take = 1 + result;
            }
        }

        return dp[ind][target] = min(take, nottake);
    }

public:
    int numSquares(int n) {
      vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
       
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};