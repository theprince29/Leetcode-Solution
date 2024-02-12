class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<long,long>mp;
        for(int i=0; i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
       
        set<int>s(nums.begin(),nums.end());
        int maxi = INT_MIN;
        int majority;
       for(auto x : s) {
            if(maxi < mp[x]) { 
                majority = x;
                maxi = mp[x]; 
            }
        }
        
        
        if(maxi > nums.size() / 2)
            return majority;
        else
            return -1;
    }
};