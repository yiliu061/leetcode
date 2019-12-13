class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {}; //!
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        
        while(!q.empty()){ //why while(root || !q.empty()) error: time limit exceeded?
            vector<int> curr_lev;
            
            for (int i = q.size(); i > 0; --i){
                TreeNode* tmp = q.front();
                curr_lev.push_back(tmp->val);
                q.pop();
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(curr_lev);
        }
        return res;
    }
};
