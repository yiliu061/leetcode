//backtracking
//! node-> val can be negative

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr;
        
        explore(root, sum, curr, res);
        return res;
    }
private:
    void explore(TreeNode* root, int sum, vector<int> curr, vector<vector<int>>& res){
        if (!root) return; 
        
        curr.push_back(root->val);
        if (sum == root->val && !root->left && !root->right) res.push_back(curr);
        
        explore(root->left, sum - root->val, curr, res);
        explore(root->right, sum - root->val, curr, res);
        curr.pop_back();
    }
};
