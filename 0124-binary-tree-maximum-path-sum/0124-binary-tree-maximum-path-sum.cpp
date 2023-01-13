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
    int solution(TreeNode* root, int &ans){
        if(root==NULL){
            return 0;
        }
        int rightSum= max(0, solution(root->right, ans));
        int leftSum= max(0, solution(root->left, ans));
        
        int sum= root->val + rightSum + leftSum;
        ans= max(ans, sum);
        
        return max(rightSum, leftSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=-1e7;
        solution(root, ans);
        return ans;
    }
};