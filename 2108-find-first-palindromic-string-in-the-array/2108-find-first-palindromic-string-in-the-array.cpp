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
    bool ispali(string& s) {
        int start = 0;
        int end = s.size() - 1;
        
        while (start <= end) {
            // Return false if the characters are not the same.
            if (s[start] != s[end]) {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
};