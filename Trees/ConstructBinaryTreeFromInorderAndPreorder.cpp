/*
Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
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
int findIndex(vector<int> &inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b]==val)
            return b;
}
TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(preorder[p++]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->left = makeTree(preorder, inorder, i, in-1, p);
    node->right = makeTree(preorder, inorder, in+1, j, p);
    return node;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
        return NULL;
    int p = 0;
    return makeTree(preorder, inorder, 0, inorder.size()-1, p);
}

////////////2nd Approach//////////////////////////////////
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  TreeNode* buildT(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd) {
      if(preStart > preEnd || inStart > inEnd) {
          return 0;
      }
      TreeNode*root = new TreeNode(preorder[preStart]);
      int inRoot = mp[root->val];// direct access to the element usig map
      int numsLeft = inRoot - inStart;
      root->left = buildT(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
      root->right = buildT(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
      
      return root;
  }
  
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    map<int, int> mp;
    
    for(int i = 0; i < B.size(); i++) {
        mp[B[i]] = i;
    }
    TreeNode*root = buildT(A, 0, A.size()-1, B, 0, B.size()-1, mp);
    return root;
    
}

