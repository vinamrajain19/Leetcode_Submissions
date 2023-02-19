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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while(q.size() !=0){
            
            int n = q.size();
            vector<int> temp(n,0);
            
            for(int i  = 0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(flag){
                    temp[i] = node->val;
                }
                else{
                    temp[n-i-1] = node->val;
                }
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};