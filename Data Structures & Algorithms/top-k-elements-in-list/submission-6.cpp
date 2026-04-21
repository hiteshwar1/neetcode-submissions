class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<vector<int>> freq(nums.size()+1);

        for(auto i: nums) m[i]++;
        for(auto i:m) freq[i.second].push_back(i.first);
        
        vector<int> res;
        for(int i = freq.size() - 1; i > 0 ; i--){
            for(auto j: freq[i]){
                res.push_back(j);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};
