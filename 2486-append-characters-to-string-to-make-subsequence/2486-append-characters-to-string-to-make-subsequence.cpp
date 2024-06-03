class Solution {
public:
    int appendCharacters(string s, string t) {
     
    int s_pointer = 0;
    int t_pointer = 0;
    
    int append_count = 0;
    
    
    while (s_pointer < s.length() && t_pointer < t.length()) {

        if (s[s_pointer] == t[t_pointer]) {
            s_pointer++;
            t_pointer++;
        }

        else {
            s_pointer++;
            append_count++;
        }
    }
    

    append_count = t.length() - t_pointer;
    
    return append_count;
        
    }
};