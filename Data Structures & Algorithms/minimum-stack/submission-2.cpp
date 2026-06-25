class MinStack {
   public:
    stack<int> st;
    stack<pair<int, int>> minst;
    MinStack() {
        st = stack<int>();
        minst = stack<pair<int, int>>();
    }

    void push(int val) {
        st.push(val);
        if (!minst.empty()) {
            if (minst.top().first == val) {
                minst.top().second++;
            } else if (minst.top().first > val) {
                minst.push({val, 1});
            }
        } else {
            minst.push({val, 1});
        }
    }

    void pop() {
        if (st.top() == minst.top().first) {
            minst.top().second--;
            if (minst.top().second == 0) {
                minst.pop();
            }
        }
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minst.top().first; }
};
