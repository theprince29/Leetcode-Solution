class Solution {
public:
    
int findLeft(const vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


int findRight(const vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

vector<int> targetIndices(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());

    
    int leftIdx = findLeft(nums, target);
    int rightIdx = findRight(nums, target);

    
    if (leftIdx == rightIdx) {
        return {};
    }

    
    vector<int> result;
    for (int i = leftIdx; i < rightIdx; ++i) {
        result.push_back(i);
    }

    return result;
}
};