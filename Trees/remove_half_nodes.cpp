/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    
    if(A==NULL) {
        return NULL;
    }
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    if(A->left == NULL && A->right == NULL) {
        return A;
    }
    if(A->left==NULL) {
        TreeNode*curr = A->right;
        delete(A);
        return curr;
        cout << curr->val << endl;
    }
      if(A->right==NULL) {
        TreeNode*curr = A->left;
        free(A);
        return curr;
    }
    
    return A;
}
