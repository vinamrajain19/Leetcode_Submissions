class Solution {
public:
    
bool subsetSumToK(vector<int> &arr,int k){
    int n = arr.size();
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool no = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= no||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}
    
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        for(auto it : arr){
            sum += it;
        }
        
        if(sum % 2 != 0) return false;
        else{
            return subsetSumToK(arr,sum/2);
        }
    }
};