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
    long long kthLargestLevelSum(TreeNode* root, int k) {

     if (root == nullptr) return -1; 

        vector<long long> levelSums;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            
            if (level >= levelSums.size()) {
                levelSums.push_back(0);
            }

            levelSums[level] += node->val;

            if (node->left != nullptr) {
                q.push({node->left, level + 1});
            }

            if (node->right != nullptr) {
                q.push({node->right, level + 1});
            }
        }

        if (k > levelSums.size()) return -1;

        
        sort(levelSums.rbegin(), levelSums.rend());

        return levelSums[k - 1];
    }
};