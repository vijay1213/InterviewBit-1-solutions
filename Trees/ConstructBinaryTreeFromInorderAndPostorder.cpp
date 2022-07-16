/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-postorder/
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findIndex(vector<int>& inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b] == val)
            return b;
}

TreeNode* makeTree(vector<int> &inorder, vector<int> &postorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(postorder[p--]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->right = makeTree(inorder, postorder, in+1, j, p);
    node->left = makeTree(inorder, postorder, i, in-1, p);
    return node;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int p = postorder.size()-1;
    return inorder.empty() ? NULL : makeTree(inorder, postorder, 0, inorder.size()-1, p);
}





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
   /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ///////////////////////2nd//////////////////////////////////////////
 
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    
    if(A.size()!=B.size()) {
        return NULL;
    }
    map<int, int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]] = i;
    }
    return buildTree(A, 0, A.size()-1, B, 0, B.size()-1, mp);
}
TreeNode*buildTree(vector<int> &A, int is, int ie, vector<int> &B, int ps, int pe, map<int, int> &mp) {
    if(is > ie || ps > pe) {
        return NULL;
    }
    TreeNode*root = new TreeNode(B[pe]);
    
    int inRoot = mp[B[pe]];
    int numsLeft = inRoot - is;
    
    root->left = buildTree(A, is, inRoot-1, B, ps, ps+numsLeft-1, mp);
    
    root->right = buildTree(A, inRoot+1, ie, B, ps+numsLeft, pe-1, mp);
    
    return root;
}

};
