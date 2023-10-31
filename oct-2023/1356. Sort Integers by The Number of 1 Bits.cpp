Problem Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2023-10-30


class Solution {
public:

  static bool compare(int a, int b) {
    // Create bitsets for integers a and b
    std::bitset<32> bitA(a);
    std::bitset<32> bitB(b);

    // Count the number of set bits (1's) in each bitset
    int countA = bitA.count();
    int countB = bitB.count();

    // Compare the count of set bits
    if (countA == countB) {
        return a < b;  // In case of a tie, sort in ascending order
    }

    return countA < countB;  // Sort by the number of set bits
}

static vector<int> sortByBits(std::vector<int>& arr) {
    sort(arr.begin(), arr.end(), compare);
    return arr;
}
};
