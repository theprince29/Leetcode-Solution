class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
      vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
          
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        int maxi = 0;
        int mi=ans[0].second;

        for(auto&[val,idx]:ans){
            maxi=max(maxi,idx-mi);
            mi =  min(mi,idx);
        }
        return maxi;
    }
};