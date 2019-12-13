
// method 1: recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        explore(root, res);
        return res;
    }
    
    void explore(TreeNode* root, vector<int>& res){
        if(!root) return;
        
        explore(root->left, res);
        res.push_back(root->val);
        explore(root->right, res);
    }
};



// method 2: iteration

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        while(root || !stk.empty()){ //! or
            while(root){ //find the left most leaf
                stk.push(root);
                root = root->left;
            }
            //now, root points to an nullptr
            root = stk.top(); //!
            stk.pop();
            
            res.push_back(root->val);
            
            root = root->right;            
        }
        return res;
    }
};
