//DP: let dp[i] to be the min cost to reach the i-th step

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n + 1, 0); // need n steps to go to the top floor
        
        //dp[0] = 0;dp[1] = 0;        
        for (int i = 2; i <= n; ++i){
            dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
        }
        
        return dp.back();
    }
};
