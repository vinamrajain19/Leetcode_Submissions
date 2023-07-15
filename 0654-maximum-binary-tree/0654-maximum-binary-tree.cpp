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
    
    TreeNode * f(vector<int> &nums,int s,int e){
        
        if(s > e) return NULL;
        
        int id = -1;
        int mx = -1e9;
        for(int i = s;i<=e;i++){
            if(nums[i] > mx){
                mx = nums[i];
                id = i;
            }
        }
        
        TreeNode * root = new TreeNode(mx);
        
        root->left = f(nums,s,id-1);
        root->right = f(nums,id+1,e);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(nums,0,nums.size()-1);
    }
};