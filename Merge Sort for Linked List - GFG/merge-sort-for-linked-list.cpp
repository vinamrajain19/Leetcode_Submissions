//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node * merge(Node * f,Node * s){
        Node * n = new Node(0);
        Node * temp = n;
        
        while(f and s){
            if(f->data < s -> data){
                Node * x = new Node(f->data);
                temp -> next = x;
                temp = x;
                f = f->next;
            }
            else {
                Node * x = new Node(s->data);
                temp -> next = x;
                temp = x;
                s = s->next;
            }
        }
        
        while(f){
             Node * x = new Node(f->data);
             temp -> next = x;
             temp = x;
             f = f->next;
        }
        
        while(s){
             Node * x = new Node(s->data);
             temp -> next = x;
             temp = x;
             s = s->next;
        }
        
        return n->next;
    }
    
    Node* mergeSort(Node* head) {
        
        if(head == NULL or head -> next == NULL) return head;
        // your code here
        Node * slow = head;
        Node * fast = head;
        Node * temp =slow;
        
        while(fast and fast -> next){
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        temp -> next = NULL;
        Node * f = mergeSort(head);
        Node * s = mergeSort(slow);
        
        return merge(f,s);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends