//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int s = 0;
        int e = n1;
        
        
        while(s <= e){
            int cut1 = (s+e)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            
            int l1 = cut1 == 0 ? -1e9 : nums1[cut1-1];
            int l2 = cut2 == 0 ? -1e9 : nums2[cut2-1];
            int r1 = cut1 == n1 ? 1e9 : nums1[cut1];
            int r2  = cut2 == n2 ? 1e9 : nums2[cut2];
            
            if(l1 <= r2 and l2 <= r1){
                if((n1+n2) % 2 == 0) {
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }
                else return max(l1,l2);
            }
            else if(l1 > r2){
                e = cut1-1;
            }
            else s = cut1+1;
        }
        
        return 0.0;
        
        
    }
    
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        return findMedianSortedArrays(array1,array2);
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends