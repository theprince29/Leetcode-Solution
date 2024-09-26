class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> v;
        int i = 1;
        while(pow(i, x) <= n){
            v.push_back(pow(i, x));
            i++;
        }

        int dp[n+1];
        int mod = 1e9+7;

        dp[0] = 1;

        for(int i=1; i<=n; i++){
            dp[i] = 0;
        }

        for(auto j: v){
            for(int i=n; i>j-1; i--){
                dp[i] = (dp[i] + dp[i-j])%mod;
            }
        }
        
        return dp[n];
    }
};