class Solution {
    int ans = 0;

public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        // Update the maximum diameter
        ans = max(ans, left + right);

        // Return the height
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};
