//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    
    vector<int>  ms(int arr1[],int arr2[],int n,int m){
        int i = 0;
        int j = 0;
        int k =0;
        
        vector<int> v(n+m,0);
        
        while(i < n and j < m){
            if(arr1[i] < arr2[j]){
                v[k++] = arr1[i++];
            }
            else v[k++] = arr2[j++];
        }
        
        while(i < n){
            v[k++] = arr1[i++];
        }
        
        while(j < m){
            v[k++] = arr2[j++];
        }
        
        return v;
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> ans = ms(arr1,arr2,n,m);
        
        return ans[k-1];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends