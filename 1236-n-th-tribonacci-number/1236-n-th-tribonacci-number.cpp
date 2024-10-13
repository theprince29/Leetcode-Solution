class Solution {
public:


    int help(int t,vector<int>&dp)
    {
        if(t==0)
            return 0;
        if(t==1)
            return 1;
        if(t==2)
            return 1;

            

       

        return dp[t]=help(t-3,dp)+help(t-2,dp)+help(t-1,dp);
    }

    int tribonacci(int n) {
           if (n == 0)
                return 0;
            if (n == 1)
                return 1;
            if (n == 2)
                return 1;

            vector<int> dp(n + 1, -1);

            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;

            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
            }

        return dp[n];
    }
};