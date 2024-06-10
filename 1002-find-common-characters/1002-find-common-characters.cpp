class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
     
       vector<int> v1(26, 0); 
        
        
        for (char x : words[0]) {
            v1[x - 'a']++;
        }
        
        
        for (int i = 1; i < words.size(); i++) {
            vector<int> v2(26, 0);
            for (char x : words[i]) {
                v2[x - 'a']++;
            }
            
        
            for (int j = 0; j < 26; j++) {
                v1[j] = min(v1[j], v2[j]);
            }
        }
        
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (v1[i] > 0) {
                result.push_back(string(1, i + 'a'));
                v1[i]--;
            }
        }
        
        return result;
    }
};