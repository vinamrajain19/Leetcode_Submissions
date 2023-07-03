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
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        return f(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1);
    }
    
    TreeNode * f(vector<int>& preorder, vector<int>& inorder,int inS,int inE,int preS,int preE){
        
        if((inS > inE) or (preS > preE)){
           return NULL;
        }
        
        int root_value = preorder[preS];
        int root_index = -1;
        for(int i = inS;i<=inE;i++){
            if(inorder[i] == root_value){
                root_index = i;
                break;
            }
        }
        
        int linS = inS;
        int linE = root_index - 1;
        int lpreS = preS + 1;
        int lpreE = linE - linS + lpreS;

        int rinS = root_index + 1;
        int rinE = inE;
        int rpreS = lpreE + 1;
        int rpreE = preE;
        
        TreeNode * root = new TreeNode(root_value);
        root->left = f(preorder,inorder,linS,linE,lpreS,lpreE);
        root->right = f(preorder,inorder,rinS,rinE,rpreS,rpreE);
        
        return root;
    }
};