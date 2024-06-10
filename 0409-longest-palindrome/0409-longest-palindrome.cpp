class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        
        for(char x : s)
        {
            mp[x]++;
        }
        
        int count = 0;
        bool odd_found = false;
        
        for (auto x : mp) {
            if (x.second % 2 == 0) {
                count += x.second;
            } else {
                count += x.second - 1;
                odd_found = true;
            }
        }
        
        if (odd_found) {
            count += 1;
        }
        return count;
    }
};