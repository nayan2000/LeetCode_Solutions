/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insertHelper(TreeNode* &root, int val){
        if(root == NULL){
            root = new TreeNode(val);
            return;
        }
        
        if(root->val > val){
            insertHelper(root->left, val);
        }
        else if(root->val < val){
            insertHelper(root->right, val);
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertHelper(root, val);
        return root;
    }
};