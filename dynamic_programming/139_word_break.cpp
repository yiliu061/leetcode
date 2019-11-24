//DP: let dp[i] to be whether the word in [0,i] interval can be segmented

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, true);
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); //!
        
        
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < i; ++j){
                string sub = s.substr(j, i-j);
                dp[i] = dp[j] && dict.count(sub); 
                if (dp[i]) break;
            }    
        }
        return dp.back();
    }
};
