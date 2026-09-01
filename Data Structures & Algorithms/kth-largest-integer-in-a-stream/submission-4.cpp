class KthLargest {
    priority_queue<int, vector<int>, greater<int>> q;
    int k;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        q = priority_queue<int, vector<int>, greater<int>>();
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() < k) {
                q.push(nums[i]);
            } else if (q.top() < nums[i]) {
                q.pop();
                q.push(nums[i]);
            }
        }
    }

    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};
