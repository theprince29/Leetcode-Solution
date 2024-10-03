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
    void func(TreeNode* root, vector<int>&vs)
    {
        if(root==NULL)
        {
            return ;
        }
        func(root->left,vs);
        vs.push_back(root->val);
        func(root->right,vs);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>vs;
        func(root,vs);
         int left = 0;
        int right = vs.size() - 1;

        while (left < right) {
            int sum = vs[left] + vs[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left++;  
            } else {
                right--; 
            }
        }
        
        return false;  
    }
};