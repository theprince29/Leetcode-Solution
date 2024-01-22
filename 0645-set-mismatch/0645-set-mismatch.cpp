class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        vector<int>v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] ==nums[i])
            {
                v.push_back(nums[i]);
            }
            else
            {
                res+=nums[i];
            }
        }
        
        v.push_back(((n*(n+1))/2) - res);
        
        
        return v;
    }
};