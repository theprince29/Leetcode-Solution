class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int x: nums)
        {
            mp[x]++;
        }
        vector<pair<int,int>>vp;
        for(auto x: mp)
        {
            vp.push_back({x.second,x.first});
        }
        sort(vp.begin(), vp.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first < b.first; 
        });
        vector<int>ans;

        for(auto x:vp)
        {
            for(int i=1; i<=x.first;i++)
            { 
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};