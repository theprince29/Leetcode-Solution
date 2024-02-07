class Solution {
public:
    string frequencySort(string s) {
     map<char,int>mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            
        }
        
        vector<pair<char, int>> pairs;
        for (const auto& pair : mp) {
            pairs.push_back(pair);
        }

        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {return a.second > b.second;});
        
        std::string ans = "";
        for (const auto& x : pairs) {
            ans += std::string(x.second, x.first);
        }
        return ans;
    
    }
};