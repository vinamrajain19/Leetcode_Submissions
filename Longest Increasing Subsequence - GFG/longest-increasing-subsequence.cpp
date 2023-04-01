//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        
        for(int i = 1;i<nums.size();i++){
            if(temp.back() >= nums[i]){
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
            else{
                len++;
                temp.push_back(nums[i]);
            }
        }
        
        return len;
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> v;
       for(int i = 0;i<n;i++) v.push_back(a[i]);
       return lengthOfLIS(v);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends