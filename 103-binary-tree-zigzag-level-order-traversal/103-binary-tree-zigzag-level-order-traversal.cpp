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
    vector<vector<int>> zigzagLevelOrder(TreeNode* node) {
        vector<vector<int>> ans;
        if(node == NULL){
            return ans;
        }
        
        queue<TreeNode *> q;
        q.push(node);
    
        int flag = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            for(int i = 0;i<n;i++){
                TreeNode * temp = q.front();
                q.pop();
                t.push_back(temp->val);
          
                if(temp->left){
                    q.push(temp->left);
                }
          
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(flag % 2 == 0){
                ans.push_back(t);
            }
            else{
                reverse(t.begin(),t.end());
                ans.push_back(t);
            }
            flag++;
            
      }
        
        return ans;
    }
};