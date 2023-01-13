```
class Solution {
public:
bool isLeaf(TreeNode* root){
return (root->left==NULL) && (root->right==NULL);
}
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
```