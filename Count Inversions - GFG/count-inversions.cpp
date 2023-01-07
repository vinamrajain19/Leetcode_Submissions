//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans = 0;
    
    void merge(long long arr[],long long N,long long s,long long m,long long e){
        long long i = s;
        long long j = m+1;
        long long k = 0;

        long long temp[e-s+1];
        
        while(i <= m and j <= e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                ans += m+1-i;
            }
        }
        
        while(i <= m){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        k = 0;
        for(int l = s;l<=e;l++){
            arr[l] = temp[k++];
        }
        return;
    }
    
    
   void mergesort(long long arr[],long long N,long long s,long long e){
        if(s >= e) return;
        
        
        long long mid = (s+e)/2;
        mergesort(arr,N,s,mid);
        mergesort(arr,N,mid+1,e);
        merge(arr,N,s,mid,e);
    }
    
    
    long long int inversionCount(long long arr[], long long N){
        mergesort(arr,N,0,N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends{
