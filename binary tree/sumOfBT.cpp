// Given a binary tree, find the sum of values of all the nodes. 



class Solution {
  public:
    int sumBT(Node* root) {
        
        if(root==NULL)return 0;
        int leftSum = sumBT(root->left);
        int rightSum = sumBT(root->right);
        
        return leftSum + rightSum + root->data;
    }
};