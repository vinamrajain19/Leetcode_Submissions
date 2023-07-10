/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<Node *> q;;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            vector<int> tm;
            while(n--){
                Node * t = q.front();
                q.pop();
                
                if(t != NULL) tm.push_back(t->val);
                
                for(auto it : t->children){
                    if(it != NULL) q.push(it);
                }
            }
            ans.push_back(tm);
        }
        return ans;
    }
};