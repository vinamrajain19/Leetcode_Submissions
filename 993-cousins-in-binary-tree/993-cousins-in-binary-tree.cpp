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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode * p1 = NULL;
        TreeNode * p2 = NULL;
        
        int d1 = -1;
        int d2 =-1;
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() != 0){
            int n = q.size();
            while(n--){
                TreeNode * t = q.front();
                q.pop();
                
                if(t->left){
                    q.push(t->left);
                    if(t->left->val == x){
                        p1 = t;
                        d1 = level+1;
                    }
                    if(t->left->val == y){
                        p2 = t;
                        d2 = level+1;
                    }
                }
                
                if(t->right){
                    q.push(t->right);
                    if(t->right->val == x){
                        p1 = t;
                        d1= level+1;
                    }
                    if(t->right->val == y){
                        p2 = t;
                        d2 = level+1;
                    }
                }
            }
            level++;
        }
        
        if(d1 == d2){
            if(p1 != p2) return true;
            return false;
        }
        return false;
    }
};