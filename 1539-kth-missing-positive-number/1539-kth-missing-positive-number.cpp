class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0;
        int e = arr.size()-1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(arr[m] - (m+1) >= k){
                e = m-1;
            }
            else s = m +1;
        }
        
        return k + s;
        
    }
};