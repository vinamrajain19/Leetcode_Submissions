//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  int f(vector<int> &nums,int s){
        if(s < 0) return 0;
        
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int ans = 0;
        
        while(j < nums.size()){
            
            sum += nums[j];
            
            while(sum > s and i < nums.size()){
                sum -= nums[i];
                i++;
            }
            
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        return f(arr,target) - f(arr,target -1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends