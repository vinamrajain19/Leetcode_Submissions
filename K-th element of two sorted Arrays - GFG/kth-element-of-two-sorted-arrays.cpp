//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       int i = 0;
       int j = 0;
       int z  = 0;
       
       while( i< n and j < m){
           if(arr1[i] <= arr2[j]){
               i++ ,z++;
               if(z == k) return arr1[i-1];
           }
           else{
               j++,z++;
               if(z== k) return arr2[j-1];
           }
       }
       
       while(i<n){
           i++;
           z++;
           if(z == k) return arr1[i-1];
       }
       
       while(j<m){
           j++;
           z++;
           if(z == k) return arr2[j-1];
       }
       
       return -1;
       
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