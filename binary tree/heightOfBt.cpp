// Given the root of a binary tree, find the maximum depth of the tree.

// Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.


class Solution {
  public:
    int height(Node* root) {
        if(root == NULL){
            return -1;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right) + 1;
        return ans;
    }
};