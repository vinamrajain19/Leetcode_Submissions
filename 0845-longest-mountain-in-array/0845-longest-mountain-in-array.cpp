class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int i = 1;
        while(i<arr.size()-1){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
                //peak found
                int cnt = 1;
                int idx = i;
                while(i < arr.size()-1 and arr[i] > arr[i+1]){
                    cnt++;
                    i++;
                }
                
                while(idx >= 1 and arr[idx] > arr[idx-1]){
                    cnt++;
                    idx--;
                }
                
                ans = max(ans,cnt);
            }
            else i++;
        }
        return ans;
    }
};