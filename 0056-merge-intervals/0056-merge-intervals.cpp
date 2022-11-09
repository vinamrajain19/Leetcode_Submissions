class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& it) {
        vector<vector<int>> ans;
        sort(it.begin(),it.end(),cmp);
        vector<int> temp = it[0];
        
        for(int i = 1;i<it.size();i++){
               if(it[i][0] <= temp.back()){
                   temp[0] = min(temp[0],it[i][0]);
                   temp[1] = max(temp[1],it[i][1]);
               }
               else{
                   ans.push_back(temp);
                   temp = it[i];
               }
            cout<<temp[0] << " "<<temp[1];
        }
        
        ans.push_back(temp);
        return ans;
    }
};