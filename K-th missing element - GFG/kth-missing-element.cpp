//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
        int s = 0;
        int e = n-1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(a[m] - (m+a[0]) >= k){
                e = m-1;
            }
            else s = m +1;
        }
        
        int ans = k + a[0] + s -1;
        if(ans < a[n-1]) return ans;
        return  -1;
        
}