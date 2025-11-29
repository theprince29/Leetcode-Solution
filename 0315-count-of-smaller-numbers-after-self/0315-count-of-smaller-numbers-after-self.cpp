class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, result);
        return result;
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right,
                   vector<int>& result) {
        if (left >= right)
            return;

        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, result);
        mergeSort(arr, mid + 1, right, result);

        merge(arr, left, mid, right, result);
    }

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right,
               vector<int>& result) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                rightCount++;
                temp[k++] = arr[j++];
            } else {
                result[arr[i].second] += rightCount;
                temp[k++] = arr[i++];
            }
        }

        while (i <= mid) {
            result[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            arr[left + p] = temp[p];
        }
    }
};
