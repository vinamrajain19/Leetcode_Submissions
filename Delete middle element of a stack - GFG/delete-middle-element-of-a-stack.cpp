//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int size)
    {
        // code here.. 
        int n = s.size();
    stack<int> tempSt;
    int count = 0;
     
    // Put first n/2 element of st in tempSt
    while (count < n / 2) {
        int c = s.top();
        s.pop();
        tempSt.push(c);
        count++;
    }
       
    // Delete middle element
    s.pop();
       
    // Put all (n/2) element of tempSt in st
    while (!tempSt.empty()) {
        s.push(tempSt.top());
        tempSt.pop();
    }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends