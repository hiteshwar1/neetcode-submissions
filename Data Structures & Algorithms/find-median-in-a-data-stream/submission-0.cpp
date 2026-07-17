class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

   public:
    MedianFinder() {
        small = priority_queue<int>();
        large = priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num) {
        if (small.empty() || num < small.top()) small.push(num);
        else large.push(num);
        if (small.size() > large.size() + 1) {
            int res = small.top();
            small.pop();
            large.push(res);
        } else if (small.size() < large.size()) {
            int res = large.top();
            large.pop();
            small.push(res);
        }
    }

    double findMedian() {
        if (small.size() == large.size()) return (small.top() + large.top()) / 2.0;
        return small.top();
    }
};
