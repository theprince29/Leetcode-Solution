class Solution {
public:

   bool ispali(int i, int j, const std::string& s) {
    while(i < j) {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int countSubstrings(const std::string& s) {
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            if(ispali(i, j, s)) 
                count++;
        }
    }
    return count;
}
};