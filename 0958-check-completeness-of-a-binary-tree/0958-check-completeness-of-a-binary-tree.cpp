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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return 1;
       
        queue<TreeNode*>q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            if(temp->left)
            {
                if(f==1)    
                    return 0;
                q.push(temp->left);
            }
            else
                f=1;

            if(temp->right)
            {
                q.push(temp->right);
                if(f==1) 
                    return 0;

            }  
            else
                f=1;

        }
        return 1;

        
      
    }

};