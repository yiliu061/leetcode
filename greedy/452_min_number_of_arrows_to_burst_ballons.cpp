//greedy, count the number of local min

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        
        //! process the 1st interval, because if input only has one interval, if (points[i][0] > mx_end) won't be true forever.
        int mx_end = points[0][1];
        int res = 1;
        
        for (int i = 1; i < points.size(); ++i){
            if (points[i][0] > mx_end){
                ++res;
                mx_end = points[i][1];
            } else{
                mx_end = min(mx_end, points[i][1]);
            }
        }
        return res;

    }
};
