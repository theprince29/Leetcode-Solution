class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>v= nums;
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i =0 ; i <nums.size();i++)
        {
            if(v[i]==target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};