class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freqArr(nums.size() + 1);
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i = m.begin();i!=m.end();i++){
            freqArr[i->second].push_back(i->first);
        }
        vector<int> res;
        for(int i=freqArr.size()-1;i>0;i--){
            for(auto n: freqArr[i]){
                res.push_back(n);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
