class Solution {

private:
    int lcs(string str1,string str2)
    {
        int n =  str1.length();
        int m = str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =0 ; i  <=n; i++ ) dp[i][0] = 0;
        for(int j =0 ; j <=m; j++ ) dp[0][j] = 0 ;

        for(int i =1; i<= n ;i++)
        {
            for(int j = 1 ; j <=m;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2) {
        return ((word1.length()+word2.length()) - 2*lcs(word1,word2))    ;
    }
};