class Solution {
private:
    int fun(vector<int>& nums, int target, int l, int h) {
        if (l > h) return -1;

        int mid = l + (h - l) / 2;  

        if (nums[mid] == target) {
            return mid;
        } 
        else if (nums[mid] > target) {
            return fun(nums, target, l, mid - 1);  
        } 
        else {
            return fun(nums, target, mid + 1, h);  
        }
    }

public:
    int search(vector<int>& nums, int target) {
        return fun(nums, target, 0, nums.size() - 1); 
    }
};
