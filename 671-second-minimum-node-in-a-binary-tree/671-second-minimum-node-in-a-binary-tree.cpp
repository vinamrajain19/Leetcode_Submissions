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
    
    void p(TreeNode * root,set<int> &s){
        if(root == NULL) return;
        p(root->left,s);
        s.insert(root->val);
        p(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) return 0;
        
        set<int> s;
        p(root,s);
        
        if(s.size() == 1) return -1;
        
        auto a = s.begin();
        a++;
        return *a;
        
    }
};