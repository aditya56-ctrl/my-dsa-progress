void solve(BinaryTreeNode<int> *root,int& count){
    if(root == NULL)return;
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    solve(root->left,count);
    solve(root->right,count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count = 0;
    solve(root,count);
    return count;
}