class Solution {

private:
    int lowerBound(vector<int>nums,int target)
    {
        int  l = 0;
        int  h = nums.size() -1;
        int ans = nums.size() ; 
        while(l<= h)
        {
            int mid = (l+h)>>1;
            if(nums[mid]>=target)
            {
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }    


    int uppperBound(vector<int>nums,int target)
    {
        int l = 0 ;
        int h = nums.size() -1 ;
        int ans = nums.size() ;
        while(l<=h)
        {
            int mid = (l+h)>>1;
            if (nums[mid] > target) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        int n = nums.size();
        if(lb == n || nums[lb] != target) return {-1,-1};

        return {lb,uppperBound(nums,target)-1};
        
    }
};