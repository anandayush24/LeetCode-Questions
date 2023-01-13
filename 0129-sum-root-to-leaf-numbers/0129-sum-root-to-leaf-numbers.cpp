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
    bool isLeaf(TreeNode* root){
        return (root->left==NULL) && (root->right==NULL);
    }
    int i=0;
    void solution(TreeNode* root, int temp, int &ans){
        temp= (10*temp) + root->val;
        if(isLeaf(root)){
            ans+= temp;
        }
        if(root->right!=NULL){
            solution(root->right, temp, ans);
        }
        if(root->left!=NULL){
            solution(root->left, temp, ans);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int temp=0, ans=0;
        solution(root, temp, ans);
        return ans;
    }
};