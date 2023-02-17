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
    long long ans=INT_MAX;
    long long x=INT_MIN;
    int minDiffInBST(TreeNode* root) {
        func(root);
        return ans;
    }
    void func(TreeNode* root){
        if(root->left)
            func(root->left);
        ans=min(ans, abs(x-root->val));
        x=root->val;
        if(root->right)
            func(root->right);
    }
};