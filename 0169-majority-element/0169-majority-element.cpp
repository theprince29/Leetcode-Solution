class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<long,long>mp;
        for(int i=0; i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
       
        int ans;
        for(auto c :mp)
        {
            if(c.second>nums.size()/2){
                ans = c.first;
                break;
            }
        }
        return ans;
}
};