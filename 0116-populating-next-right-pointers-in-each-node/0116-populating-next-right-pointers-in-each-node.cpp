/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //Basic Level Order traversal -> acc to ques -> in diagram -> we see -> last node of every level -> next -> NULL else other node -> next -> next node in same level i.e. -> q.front().
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node *> q;
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
            for(int i = 0;i<n;i++){
                Node * temp = q.front();
                q.pop();
                if(i == n-1) temp->next = NULL;
                else temp -> next = q.front();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};