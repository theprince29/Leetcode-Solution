class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
     map<int,int>mp;
        for(auto x: nums)
        {
            mp[x]++;
        }
        
        int maxi = INT_MIN;
        
        for(auto j: mp)
        {
            maxi = max(maxi,j.second);
        }
        
        
        int count =0;
        for(auto t:mp)
        {
            if(t.second == maxi)
            {
                count++;
            }
        }
        
        return count*maxi;
    }
};