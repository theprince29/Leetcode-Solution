class CustomStack {
public:
   vector<int> v;      
    int maxSize;         
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        v.reserve(maxSize);
    }
    
    
    void push(int x) {
        if (v.size() < maxSize) {
            v.push_back(x);
        }
    }
    
    
    int pop() {
        if (!v.empty()) {
            int top = v.back();  
            v.pop_back();
            return top;
        }
        return -1;
    }
    
    
    void increment(int k, int val) {
        int limit = min(k, (int)v.size());  
        for (int i = 0; i < limit; i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */