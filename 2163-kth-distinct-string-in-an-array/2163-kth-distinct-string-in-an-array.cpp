class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> frequencyMap;
        vector<string> order;

        
        for (const string& str : arr) {
            if (frequencyMap[str] == 0) {
                order.push_back(str);
            }
            frequencyMap[str]++;
        }

        
        int distinctCount = 0;
        for (const string& str : order) {
            if (frequencyMap[str] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return str;
                }
            }
        }

        
        
        return "";
    }
};