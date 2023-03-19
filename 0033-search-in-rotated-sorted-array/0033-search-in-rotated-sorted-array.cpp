class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        int ind = -1;
        while(s <= e){
            int m = (s+e)/2;

            if(arr[m] == target){
                ind= m;
                break;
            }
            else if(arr[m] >= arr[s]){
                if(arr[s] <= target and target <= arr[m]){
                    e = m;
                }
                else s = m +1;
            }
            else{
                if(arr[m]<= target and arr[e] >= target){
                    s = m;
                }
                else e = m-1;
            }
        }
        return ind;
    }
};