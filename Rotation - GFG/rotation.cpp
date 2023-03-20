//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int s = 0;
	    int e = n-1;
	    
	    if(arr[s] <= arr[e]) return 0;
	    
	    while(s < e){
	        int m = (s+e)/2;
	        
	        if(arr[m] >= arr[0]) s = m+1;
	        else e = m;
	    }
	    return s;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends