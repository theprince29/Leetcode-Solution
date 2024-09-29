class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int>maxSuffix(n+1,0);
        int i = n-1;
        int j = m-1;


        while(i>=0 && j>=0)
        {
            if(word1[i] == word2[j])
            {
                maxSuffix[i] = (m - j) ;
                i--;
                j--;
            }
            else
            {
                i--;
            }
        }

        for(int  i=n-2;i>=0;i--)
        {
            maxSuffix[i] = max(maxSuffix[i],maxSuffix[i+1]);
        }
        vector<int>ans;

        i = 0 ;
        j =0 ;
        int flag =0 ;

        while(i<n && j<m)
        {
            if(word1[i] == word2[j])
            {
                ans.push_back(i);
                i++;
                j++;
            }
            else
            {
                int rem = (m-j-1);
                if(maxSuffix[i+1] >= rem && flag ==0)
                {
                    ans.push_back(i);
                    j++;
                    i++;
                    flag = 1;
                }
                else
                {
                    i++;
                }
            }
        }
        if(ans.size() == m)
        {
            return ans;
        }
      
        
            return {};
        


    }
};