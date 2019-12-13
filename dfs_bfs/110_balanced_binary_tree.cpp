/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//method 1 use #104: O(nlogn), height is calculated logn times
class Solution {
    
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <=1;
    }
private:
    int height(TreeNode* node){
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
};


 // method2: helper function to check if the substrees are balanced, if not, return false O(n)
class Solution {
public:    
    bool isBalanced(TreeNode *root) {
        if (height(root) == -1) return false;
        else return true;
    }
private:
    int height(TreeNode *root) {
        if (!root) return 0;
        
        int left = height(root->left);
        if (left == -1) return -1;
        
        int right = height(root->right);
        if (right == -1) return -1;
        
        int diff = abs(left - right);
        if (diff > 1) return -1; //-1 == unbalanced
        else return 1 + max(left, right);
    }
};




