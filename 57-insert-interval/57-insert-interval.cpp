class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newarr) {
        vector<vector<int>> ans;
        
        for(int i = 0;i<arr.size();i++){
            
            if(newarr[0] > arr[i][1]){
                ans.push_back(arr[i]);
            }
            else if(newarr[1] < arr[i][0]){
                ans.push_back(newarr);
                newarr = arr[i];
            }
            
            else if(arr[i][1] >= newarr[0] or arr[i][0] <= newarr[1]){
                //merge
                newarr[1] = max(newarr[1],arr[i][1]);
                newarr[0] = min(newarr[0],arr[i][0]);
            }

        }
        ans.push_back(newarr);
        return ans;
    }
};