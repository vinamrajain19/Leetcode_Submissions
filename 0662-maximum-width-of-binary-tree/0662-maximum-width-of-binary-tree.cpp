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
   
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<pair<TreeNode *,long long>> q;
        q.push({root,0});
        
        int width = 0;
        
        while(q.size() != 0){
            int n = q.size();
            long long rmin = q.front().second;
            
            int first,last;
            for(int i=0;i<n;i++){
                long long curr_id = q.front().second - rmin;
                TreeNode * node = q.front().first;
                q.pop();
                
                //first index at each level
                if(i == 0) first = curr_id;
                if(i == n-1) last = curr_id;
                
                if(node->left) q.push({node->left,curr_id * 2 + 1});
                if(node->right) q.push({node->right,curr_id * 2 + 2});
            }
            
            width = max(width,last - first + 1);
        }
        
        return width;
    
    }
};