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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0; // even
        while(!q.empty()){
            int nodes = q.size();
            int prev = -1;
            while(nodes--){
                TreeNode* temp = q.front();
                q.pop();
                if(prev != -1 && level == 1){
                    if(temp -> val >= prev || (temp -> val)%2 != 0)
                        return false;
                }
                else if(prev != -1 && level == 0){
                    if(temp -> val <= prev || (temp -> val)%2 == 0)
                        return false;
                }
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
                prev = temp -> val;
                //check necessary for 1st element of every level
                if(level == 0 && prev%2 == 0) return false;
                else if(level == 1 && prev%2 == 1) return false;
            }
            level = !level;  
        }
        return true;
    }
};