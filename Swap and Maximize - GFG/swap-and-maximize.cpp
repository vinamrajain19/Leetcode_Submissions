//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    
    int i = 0;
    int j = n-1;
    
    int sum = 0;
    
    bool f = false;
    while(i < j){
        sum += arr[j] - arr[i];
        
        if(!f){
            i++;
        }
        else j--;
        
        f = !f;
    }
    
    sum += arr[j] - arr[0];
    
    return sum;
    
}