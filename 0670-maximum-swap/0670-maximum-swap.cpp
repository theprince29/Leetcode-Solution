class Solution {
public:
    int maximumSwap(int num) {
    string num_str = to_string(num);
    int n = num_str.size();

    
    vector<int> last(10, -1);
    
  
    for (int i = 0; i < n; ++i) {
        last[num_str[i] - '0'] = i;
    }
    
  
    for (int i = 0; i < n; ++i) {
  
        for (int d = 9; d > num_str[i] - '0'; --d) {
            if (last[d] > i) {
  
                swap(num_str[i], num_str[last[d]]);
  
                return stoi(num_str);
            }
        }
    }
    
  
    return num;    
    }
};