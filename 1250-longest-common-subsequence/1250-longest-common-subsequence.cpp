class Solution {

private:
    int fun(int i , int j ,string &text1 ,string &text2,vector<vector<int>>&dp)
    {
        if(i < 0 || j <0) return 0 ; 
        if(text1[i] == text2[j]) return dp[i][j] =  1+ fun(i-1,j-1,text1,text2,dp);

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] =  max(fun(i-1,j,text1,text2,dp),fun(i,j-1,text1,text2,dp));
           
    }


public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return fun(n1-1,n2-1,text1,text2,dp);
    }
};