class Solution {
public:
    int recur(vector<int>& cost, int i, vector<int> &dp){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(recur(cost,i+1,dp),recur(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(recur(cost,0,dp),recur(cost,1,dp));
    }
};
