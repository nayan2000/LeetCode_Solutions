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
    // Instead of DFS, BFS is better suited to this task because
    // if a tree is skewed, DFS traverses one side fully before exploring other side
    // while BFS will directly give the answer as soon as the first leaf is found

    // DFS approach
    // int minDepthHelper(TreeNode* root){
    //     if(!root->left && !root->right) return 1;
    //     int l = INT_MAX, r = INT_MAX;
    //     if(root->left)
    //         l = minDepthHelper(root -> left);
    //     if(root->right)
    //         r = minDepthHelper(root -> right);
    //     return 1 + min(l,r);
    // }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        // BFS approach
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            level++;
            int nodes = q.size();
            while(nodes--){
                TreeNode* root = q.front();
                q.pop();
                if(!root->left and !root->right)
                    return level;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return level;
        
        // DFS approach
        // return minDepthHelper(root);
    }
};