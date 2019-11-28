// backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        vector<int> curr;
        vector<vector<int>> res;
        
        explore(nums, 0, visited, curr, res);
        return res;
    }
    
private:
    void explore(vector<int>& nums, int level, vector<int>& visited, vector<int> curr, vector<vector<int>>& res){
        if (level == nums.size()) {res.push_back(curr); return;} //跳出条件
        
        for(int i = 0; i < nums.size(); ++i){ //每次都从头search：因是排列
            if (visited[i] == 1) continue; //没有必要用visited[nums[i]]
            else{
                visited[i] = 1;
                curr.push_back(nums[i]);
                explore(nums, level + 1, visited, curr, res);
                curr.pop_back(); //reset, go back to the last level + remove mark
                visited[i] = 0;
            }
        }
    }
};
