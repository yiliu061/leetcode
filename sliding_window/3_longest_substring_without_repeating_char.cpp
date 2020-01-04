class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; i++) {//left 是sliding win的起点-1，i是终点
            if (m.count(s[i]) && m[s[i]] > left) {//当前char在win里
                left = m[s[i]];  
            }
            m[s[i]] = i;//不在win里，存进来；在win里，用新idx覆盖旧idx，
            res = max(res, i - left);            
        }
        return res;
    }
};
