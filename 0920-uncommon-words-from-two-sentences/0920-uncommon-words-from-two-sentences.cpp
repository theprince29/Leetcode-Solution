class Solution {
private:
    vector<string>fun(string x)
    {
        vector<string> ans;
        string word = "";
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == ' ') {
                if (!word.empty()) {
                    ans.push_back(word);
                }
                word = ""; 
            } else {
                word += x[i];
            }
        }
        if (!word.empty()) {
            ans.push_back(word);  
        }
        return ans;
    }    
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> a = fun(s1);
        vector<string> b = fun(s2);

        a.insert(a.end(), b.begin(), b.end());
        unordered_map<string, int> wordCount;
        for (const string& word : a) {
            wordCount[word]++;
        }

        
        vector<string> result;
        for (const auto& pair : wordCount) {
            if (pair.second == 1) {  
                result.push_back(pair.first);
            }
        }

        return result;

    }
};