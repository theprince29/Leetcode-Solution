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
    
    void fun(TreeNode* root,int depth,int& maxDepth,int&leftValue)
    {
        if(root == nullptr) return;
        
        if (depth > maxDepth) {
            maxDepth = depth;
            leftValue = root->val;
        }
        
        fun(root->left,depth+1,maxDepth,leftValue);
        fun(root->right,depth+1,maxDepth,leftValue);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftValue = root->val;

        fun(root, 1, maxDepth, leftValue);
        return leftValue;      
    }
};