//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    #define ll long long

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int r[n],l[n];
        
        l[0] = arr[0];
        for(int i = 1;i<n;i++){
            l[i] = max(l[i-1],arr[i]);
        }
        
        r[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            r[i] = max(r[i+1],arr[i]);
        }
        
        ll ans = 0;
        for(int i = 0;i<n;i++){
            ans += min(l[i],r[i]) - arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends