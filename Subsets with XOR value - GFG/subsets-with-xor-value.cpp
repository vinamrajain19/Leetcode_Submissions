//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int f(vector<int> &arr,int N,int K,int x,int idx){
        if(idx == N and x == K) return 1;
        
        if(idx >= N) return 0;
        
        int pick = f(arr,N,K,x^arr[idx],idx+1);
        int no = f(arr,N,K,x,idx+1);
        
        return pick + no;
    }
    
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        int x = 0;
        return f(arr,N,K,x,0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends