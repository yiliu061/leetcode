//dp == 300.LIS
//dp[i] to be the max number of evenlopes at i+1-th position

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        
        int n = envelopes.size();
        vector<int> dp(n, 1); //padding
        int res = 0; 
        
        sort(envelopes.begin(), envelopes.end()); //!
        
        for(int i = 0; i < n; ++i){ //! not i = 1, because if n = 1 and we set i = 1, we won't update res. res will be 0.
            for (int j = 0; j < i; ++j){
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
