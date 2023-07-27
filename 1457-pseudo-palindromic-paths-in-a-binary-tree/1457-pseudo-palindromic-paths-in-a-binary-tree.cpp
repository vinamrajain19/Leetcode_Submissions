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
    unordered_map<int,int> m;
    int ans =0;
    void f(TreeNode * root){
        if(root == NULL) return;
        
        m[root->val]++;
        
        if(root->left == NULL and  root-> right == NULL){
            int o = 0;
            int e = 0;
            for(auto it : m){
                if(it.second % 2 == 1) o++;
                else e++;
            }
            if(o <= 1) ans++;
        }
        
        f(root->left);
        f(root->right);
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        f(root);
        return ans;
    }
};