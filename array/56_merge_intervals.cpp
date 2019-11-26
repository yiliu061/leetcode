class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; //!
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res{intervals[0]};
        for (int i = 1 ; i < intervals.size(); ++i){
            if (res.back()[1] < intervals[i][0]) res.push_back(intervals[i]); //always compare the back of the container to the i-th interval
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};
