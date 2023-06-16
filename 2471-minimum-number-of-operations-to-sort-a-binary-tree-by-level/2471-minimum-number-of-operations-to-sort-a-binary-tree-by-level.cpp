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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            vector<int> v;
            while(n--){
                TreeNode* t = q.front();
                q.pop();
                v.push_back(t->val);
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            
            vector<pair<int,int>> x;
            
            for(int i = 0;i<v.size();i++){
                x.push_back({v[i],i});
            }
            
            sort(x.begin(),x.end());
            
            int i = 0;
            while(i < v.size()){
                if(x[i].second == i or x[i].first == v[i]){
                    i++;
                }
                else{
                    ans++;
                    swap(x[i],x[x[i].second]);
                }
            }

            
            
        }
        
        return ans;
    }
};