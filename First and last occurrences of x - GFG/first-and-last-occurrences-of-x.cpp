//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> v;
    int ind1 = -1;
    
    int s = 0;
    int e = n-1;
    
    while(s <= e){
        int m = (s+e)/2;
        
        if(arr[m] == x){
            ind1 = m;
            e = m-1;
        }
        else if(arr[m] < x){
            s = m +1;
        }
        else e = m-1;
    }
    
    int ind2 = -1;
    s = 0;
    e = n-1;
    
    while(s <= e){
        int m = (s+e)/2;
        
        if(arr[m] == x){
            ind2 = m;
            s = m+1;
        }
        else if(arr[m] < x){
            s = m +1;
        }
        else e = m-1;
    }
    
    return {ind1,ind2};
    
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends