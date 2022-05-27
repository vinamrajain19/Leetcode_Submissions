class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n<=1) return arr;
        
        vector<vector<int>> ans;
        
        sort(arr.begin(),arr.end());
        
        vector<int> temp = arr[0];
        for(int i = 1;i<n;i++){
            if(temp[1] < arr[i][0]){
               //no merge -> push temp -> ans
                ans.push_back(temp);
                temp = arr[i];
            }
            else{
                //merge 
                temp[1] = max(temp[1],arr[i][1]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};



  