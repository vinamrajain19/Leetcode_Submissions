class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        
        sort(in.begin(),in.end(),cmp);
        
        vector<int> t = in[0];
        
        for(int i = 1;i<in.size();i++){
            if(t[1] < in[i][0]){
                ans.push_back(t);
                t = in[i];
            }
            else{
                t[0] = min(t[0],in[i][0]);
                t[1] = max(t[1],in[i][1]);
            }
            
            
        }   
        
        ans.push_back(t);
        return ans;
    }
};