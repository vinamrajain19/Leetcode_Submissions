class Solution {
public:
    
     int mod =(int)1e9+7;
    int findWays(vector<int> &arr, int tar)
    {
 
        vector<int> prev(tar+1,0);
    
        if(arr[0] == 0)  prev[0] = 2;
	    else prev[0] = 1;
    
        if(arr[0] != 0 and arr[0]<=tar)
            prev[arr[0]] = 1;
    
        for(int ind = 1; ind<arr.size(); ind++){
            vector<int> cur(tar+1,0);
            for(int target= 0; target<=tar; target++){
                int notTaken = prev[target];
    
                int taken = 0;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
                cur[target]= (notTaken + taken) % mod;
            }
            prev = cur;
        }
        return prev[tar];
    }
        
    
    int findTargetSumWays(vector<int>& arr, int d) {
        int sum = 0;
	    for(auto it : arr){
		    sum += it;
	    }
	    int x = (sum - d)/2;
	    if(sum-d < 0 || (sum-d)%2 != 0) return 0;
	    return findWays(arr,x);
    }
};