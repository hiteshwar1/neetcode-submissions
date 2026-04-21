class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto i = m.begin();i!=m.end();i++){
            if(q.size()<k){
                q.push({i->second,i->first});
            }
            else{
                if(q.top().first<i->second){
                    q.pop();
                    q.push({i->second,i->first});
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
