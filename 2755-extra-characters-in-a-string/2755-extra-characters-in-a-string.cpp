class Solution {
public:

    int sol(int i , string&s , unordered_set<string>&st ,int n,vector<int>&dp)
    {
        if(i>= n ) return 0;

        if(dp[i] != -1 ) return dp[i];


        int result = 1+ sol(i+1,s,st,n,dp);

        for(int j = i  ; j<n ;j++)
        {
            string curr = s.substr(i,j-i+1);
            if(st.count(curr))
            {
                result = min(result, sol(j+1,s,st,n,dp));
            }
        }
        return dp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n =  s.length();

        unordered_set<string> st(begin(dictionary),end(dictionary));
        vector<int>dp(n+1,-1);
        return sol(0 , s, st, n,dp);
    }
};