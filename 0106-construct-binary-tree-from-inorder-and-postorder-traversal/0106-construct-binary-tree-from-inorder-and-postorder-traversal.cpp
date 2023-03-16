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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        return helper(postorder,inorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    
    TreeNode * helper(vector<int>& postorder, vector<int>& inorder,int inS,int inE,int posS,int posE){
        
        if((inS > inE) or (posS > posE)){
           return NULL;
        }
        
        int root_value = postorder[posE];
        int root_index = -1;
        for(int i = inS;i<=inE;i++){
            if(inorder[i] == root_value){
                root_index = i;
                break;
            }
        }
        
        int linS = inS;
        int linE = root_index - 1;
        int lposS = posS;
        int lposE = linE - linS + lposS;

        int rinS = root_index + 1;
        int rinE = inE;
        int rposS = lposE + 1;
        int rposE = posE-1;
        
        TreeNode * root = new TreeNode(root_value);
        root->left = helper(postorder,inorder,linS,linE,lposS,lposE);
        root->right = helper(postorder,inorder,rinS,rinE,rposS,rposE);
        
        return root;
    }
};