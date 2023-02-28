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

    string dfs(TreeNode* root, unordered_map<string, int>& subtrees, vector<TreeNode*>&ans)
    {
        if(!root)
         return "T";
   
        // the key of hash table is the subtree represented in string format
        string subtree=to_string(root->val)+ ","+dfs(root->left,subtrees,ans)+","
                    +dfs(root->right,subtrees,ans);

        //the subtree already exist 
        if(subtrees[subtree]==1)
         ans.push_back(root);
       
        subtrees[subtree]++; 

        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       // to avoid more than two similar subtrees 
       //I used int not just Bool
       unordered_map<string,int>subtrees;
       vector<TreeNode*>ans;

      //Get all the subtrees and the dublicate one can be figured out from the dictionary -subtrees-
       dfs(root,subtrees,ans);
       
        return ans;
    }
};