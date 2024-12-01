class Solution {
private:
    bool binarySearch(const vector<int>& arr, int target, int excludeIndex) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target && mid != excludeIndex) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}    
public:
    bool checkIfExist(vector<int>& arr) {
      
    sort(arr.begin(), arr.end());
    
    
    for (int i = 0; i < arr.size(); ++i) {
        
        if (binarySearch(arr, 2 * arr[i], i)) {
            return true;
        }
        
        if (arr[i] % 2 == 0 && binarySearch(arr, arr[i] / 2, i)) {
            return true;
        }
    }
    return false;
    }
};