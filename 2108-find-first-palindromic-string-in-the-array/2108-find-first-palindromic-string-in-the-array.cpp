class Solution {
public:

    
    string firstPalindrome(vector<string>& words) {
        
        string ans;
        for(auto x: words)
            if(ispali(x))
            {
                ans = x;
                break;
            }
                
        return ans;
    }
private:
    bool ispali(string s)
    {
        string x = s;
            reverse(x.begin(),x.end());
        return x == s;
    }
};