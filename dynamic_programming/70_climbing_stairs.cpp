//DP: let dp[i] be the number of ways to finish the i-th step 

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        vector<int> dp(n + 1, 0); //there are n steps, 1-indexed
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2]; // there are two ways to do in the i-th step
        }
        
        return dp[n];
    }
};
