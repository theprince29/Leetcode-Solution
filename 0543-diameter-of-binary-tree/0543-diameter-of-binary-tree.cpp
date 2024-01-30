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
    int findh(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1+max(findh(root->left),findh(root->right));
    }
                     
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lefth = findh(root->left);
        int righth = findh(root->right);
        
        int diroot = lefth+righth;
        int dileft = diameterOfBinaryTree(root->left);
        int diright = diameterOfBinaryTree(root->right);
        
        return max({diroot,diright,dileft});
    }
};