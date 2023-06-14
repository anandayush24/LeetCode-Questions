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
    int ans=1e9+7;
    TreeNode* prev= NULL;
    void solution(TreeNode* root){
        if(root->left!=NULL){
            solution(root->left);
        }
        if(prev!=NULL){
            ans= min(ans, (root->val - prev->val));
        }
        prev=root;
        if(root->right!=NULL){
            solution(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        solution(root);
        return ans;
    }
};