class Solution {
private:
    
    vector<vector<int>> dp;
    int MOD = 1e9+7;
    int fun(int ind, int target, int x) {
        if (target == 0) return 1;  
        if (ind <= 0 || target < 0) return 0;  

        if (dp[ind][target] != -1) return dp[ind][target];

        int nottake = fun(ind - 1, target, x);

        int take = 0;
        if (pow(ind, x) <= target) {
            take = fun(ind - 1, target - pow(ind, x), x);
        }

        return dp[ind][target] = (nottake + take)%MOD;
    }

public:
    int numberOfWays(int n, int x) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return fun(n, n, x);
    }
};
