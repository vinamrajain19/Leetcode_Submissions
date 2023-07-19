class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return -1;
        
        int s = 1;
        int e = arr.size()-1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(arr[m] > arr[m-1] and arr[m] > arr[m+1]) return m;
            else if(arr[m] > arr[m-1]) s = m+1;
            else e = m-1;
        }
        
        return -1;
    }
};