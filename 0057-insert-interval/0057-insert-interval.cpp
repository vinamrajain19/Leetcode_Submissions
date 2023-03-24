class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        in.push_back(ni);
        
        sort(in.begin(),in.end());
        
        vector<vector<int>> ans;
        
      
        vector<int> t = in[0];
        
        for(int i = 1;i<in.size();i++){
            if(t.back() >= in[i][0]){
                t[0] = min(t[0],in[i][0]);
                t[1] = max(t[1],in[i][1]);
            }
            else{
                ans.push_back(t);
                t = in[i];
            }
        }
        
        ans.push_back(t);
        return ans;
        
        
    }
};