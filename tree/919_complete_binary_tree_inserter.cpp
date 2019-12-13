/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/


// queue and BFS: find the first node which does not have both children, insert
class CBTInserter {
public:
    CBTInserter(TreeNode* root) { //find the first node which does not have both children:curr
        head = root;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            if (!curr->left or !curr->right) break; 
            q.push(curr->left);
            q.push(curr->right);
            q.pop(); //!
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        TreeNode* curr = q.front();
        
        if (!curr->left) curr->left = node; //no need to push the child and pop the parent yet, we can do it when the right child is filled
        else{ 
            curr->right = node;
            q.push(curr->left);
            q.push(curr->right);
            q.pop();
        }
        return curr->val;
    }
    
    TreeNode* get_root() {
        return head;
    }
    
private:
    queue<TreeNode*> q;
    TreeNode* head;
    
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
