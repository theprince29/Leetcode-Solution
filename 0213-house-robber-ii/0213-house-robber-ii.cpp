class Solution {
public:
    int count(int start,int end,vector<int> &nums){
    
        int n=nums.size();
        int prev2=0;
	    int prev1=nums[start];
	    for(int i=start+1;i<end;i++){
	        
	        int left=nums[i]+prev2;
	        int right=0+prev1;
	        
	        int curr=max(left,right);

            prev2=prev1;
            prev1=curr;
        }
	    
	    return prev1;
    }
        
    int rob(vector<int>& nums) {
        int n=nums.size();

        if (n == 1) return nums[0];

        int ans1=count(0,n-1,nums);
        int ans2=count(1,n,nums);
        return max(ans1,ans2);
    }
};