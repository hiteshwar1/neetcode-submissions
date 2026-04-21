class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int l = 0, r = intervals.size() - 1;
        while(l<=r){
            int mid = (l+r)/2;
            if(intervals[mid][0]<newInterval[0]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        intervals.insert(intervals.begin() + l, newInterval);

        for(int i=0;i<intervals.size();i++){
            if(res.empty()||res.back()[1]<intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};
