/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    
    queue<TreeNode*> q;
    int max_sum = -1e9;
    int sum = 0;
    q.push(A);
    while(!q.empty()) {
        sum = 0;
       // ++lvl;
        
        for(int i = q.size(); i > 0; i--) {
        TreeNode*root = q.front();
       
        q.pop();
         sum += root->val;
        
        // if(sum > max_sum) {
        //     max_sum = sum;
        // }
        //sum = 0;
        if(root->left) {
            q.push(root->left);
            
        }
        if(root->right) {
            q.push(root->right);
        }
        }
        if(sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}
////////////////////////////////////////////////////for_level//////////////////////////////////////////
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
   int maxLevelSum(TreeNode* root) {
        int current_max = INT_MIN;
        int current_max_level = 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int current_sum = 0;
            ++level;
           for (int i = q.size(); i > 0; --i) {
                TreeNode* n = q.front();
                q.pop();
                current_sum += n->val;
                if (n->left != NULL) 
                    q.push(n->left);
                if (n->right != NULL)
                    q.push(n->right);
           }
            if (current_sum > current_max) {
                current_max = current_sum;
                current_max_level = level;
            }
        }
        return current_max_level;
    }
};
