// Problem link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// Probem name : 515. Find Largest Value in Each Tree Row


class Solution {
public:
    // Method to find the largest value in each level of a binary tree.
    std::vector<int> largestValues(TreeNode* root) {
        // Check if the root is null and return an empty vector if so.
        if (!root) return {};

        // Create a vector to store the largest values for each level.
        std::vector<int> result;

        // Create a queue to perform level order traversal of the binary tree.
        std::queue<TreeNode*> queue;
        queue.push(root);

        // Perform level order traversal.
        while (!queue.empty()) {
            int curr_level_size = queue.size();  // Get the number of nodes in the current level.
            int max_val = INT_MIN;  // Initialize the maximum value to the smallest possible integer.

            // Process all nodes in the current level.
            for (int i = 0; i < curr_level_size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                // Update the maximum value if the current node's value is larger.
                max_val = std::max(max_val, node->val);

                // Add child nodes to the queue for the next level.
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }

            // Add the maximum value of the current level to the result vector.
            result.push_back(max_val);
        }

        // Return the vector containing the largest values at each level.
        return result;
    }
};
