class Solution {
public:



    int minimumPushes(string word) {
        int t = word.size();
        unordered_map<char,int>mp;
        vector<int>v;
        for(int i=0; i<t;i++)
        {
            mp[word[i]]++;
        }
        
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        
        
        
        int res =0;
        int mask;
        
        
        int n = v.size();
        for(int i =0;i<n;i++)
        {
            if(i<=8) mask =1;
            
            if(i>=8 && i<16) mask =2;
            
            if(i>=16 && i<24) mask = 3;
            
            if(i>=24 && i<26) mask = 4;
            
            res += mask*v[i];
            
            
        }
        return res;
    }
};