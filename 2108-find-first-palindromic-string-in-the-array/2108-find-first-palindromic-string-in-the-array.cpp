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
        string filteredString;
        for(char c : s) {
        if(isalnum(c)) {
            filteredString += tolower(c);
        }
    }
    
    
    int left = 0;
    int right = filteredString.size() - 1;
    while(left < right) {
        if(filteredString[left] != filteredString[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}
};