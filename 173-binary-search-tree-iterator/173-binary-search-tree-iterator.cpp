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
class BSTIterator {
    private:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        pushallleft(root);
    }
    
    int next() {
        TreeNode * ans = s.top();
        s.pop();
        pushallleft(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return s.size() != 0;
    }
    
    private:
    void pushallleft(TreeNode * node){
        while(node){
            s.push(node);
            node = node -> left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */