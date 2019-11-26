//back tracking

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        explore(candidates, target, curr, res, 0);
        return res;
    }
    
private:
    void explore(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& res, int start){
        if (target < 0) return;
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            explore(candidates, target - candidates[i], curr, res, i);
            curr.pop_back();
        }
    }
};


  
