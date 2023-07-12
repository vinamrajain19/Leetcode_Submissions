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
    unordered_map<int,int>mp;
    int f(TreeNode *root)
    {
        if(!root)
            return 0;
        int one=f(root->left);
        int two=f(root->right);
        int curr=one +two+root->val;
        mp[curr]++;
        return curr;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>res;
        f(root);
        int maxi=INT_MIN;
        for(auto m:mp)
        {
            maxi=max(maxi,m.second);
        }
        for(auto m:mp)
        {
            if(m.second==maxi)
                res.push_back(m.first);
        }
        return res;
    }
};