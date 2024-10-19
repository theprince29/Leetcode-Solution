class Solution {
public:

    string funinv(string s)
    {
        string ans = "";
        for(char x:s)
        {
            if(x=='1')
            {
                ans +="0";
            }
            else
            {
                ans+="1";
            }
        }
    return ans;
    }

    char findKthBit(int n, int k) {
        string prev = "0";
        string curr;
        for(int i =1;i<n;i++)
        {
            string inv = funinv(prev);
            reverse(inv.begin(),inv.end());
            curr = prev +"1"+ inv;
            prev = curr;
        }
        return prev[k-1];
    }
};