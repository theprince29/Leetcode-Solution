class CustomStack {
public:
    vector<int> st; 
    vector<int> inc;
    int n;          

    CustomStack(int maxSize) {
        n = maxSize;
    }

    
    void push(int x) {
        if (st.size() < n) {
            st.push_back(x);
            inc.push_back(0); 
        }
    }

    
    int pop() {
        if (st.empty()) {
            return -1;
        }
        int ind = st.size() - 1;  
        if (ind > 0) {
            
            inc[ind - 1] += inc[ind];
        }

        
        int top_val = st[ind] + inc[ind];

        
        st.pop_back();
        inc.pop_back();

        return top_val;
    }

    
    void increment(int k, int val) {
        int ind = min(k, (int)st.size()) - 1;  
        if (ind >= 0) {
            inc[ind] += val;  
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