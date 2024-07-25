class Solution {
public:
    

void merge(vector<int> &array, int start, int middle, int end) {
    vector<int> tempArray;
    int leftIndex = start;
    int rightIndex = middle + 1;

    while (leftIndex <= middle && rightIndex <= end) {
        if (array[leftIndex] <= array[rightIndex]) {
            tempArray.push_back(array[leftIndex]);
            leftIndex++;
        } else {
            tempArray.push_back(array[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex <= middle) {
        tempArray.push_back(array[leftIndex]);
        leftIndex++;
    }

    while (rightIndex <= end) {
        tempArray.push_back(array[rightIndex]);
        rightIndex++;
    }

    for (int i = start; i <= end; i++) {
        array[i] = tempArray[i - start];
    }
}

void mergeSort(vector<int> &array, int start, int end) {
    if (start >= end) return;
    int middle = (start + end) / 2;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
}


    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};