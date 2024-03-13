class MinStack {
public:
    vector<pair<int, int>> v;
    int minVal = INT_MAX;
    
    MinStack() {}
    
    void push(int val) {
        if (v.size() == 0 || val < v[v.size() - 1].second) {
            v.push_back({val, val});
            minVal = val;
        } else {
            v.push_back({val, minVal});
        }
    }
    
    void pop() {
        v.pop_back();
        if (v.size()) minVal = v[v.size() - 1].second;
    }
    
    int top() {
        return v[v.size() - 1].first;
    }
    
    int getMin() {
        return v[v.size() - 1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */