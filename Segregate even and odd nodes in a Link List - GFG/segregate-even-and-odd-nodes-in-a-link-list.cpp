// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* evenHead = NULL;
	Node* oddHead = NULL;
	Node* eventemp = NULL;
	Node* oddtemp = NULL;
	Node* node = head;
	while(node)
	{
// 		cout << node->data << endl;
		if(node->data %2 == 0){
			if(!evenHead){
				evenHead = node;
				eventemp = node;
			}else{
				eventemp->next = node;
				eventemp = eventemp->next;
			}
		}else{
			if(!oddHead){
				oddHead = node;
				oddtemp = node;
			}else{
				oddtemp->next = node;
				oddtemp = oddtemp->next;
			}

		}
		node = node->next;
	}

	if(oddtemp)
		oddtemp->next = NULL;
	if(eventemp)
		eventemp->next = oddHead;

	if(evenHead)
		return evenHead;

	return oddHead;	
}
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends