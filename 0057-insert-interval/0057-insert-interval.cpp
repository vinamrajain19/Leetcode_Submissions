class Solution {
public:
    
    
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        vector<vector<int>> ans;
        
        int i = 0;
        
        
        // case 1 till where have not had the pos for new interval;
        while(i < in.size() and in[i][1] <  ni[0]){
            ans.push_back(in[i]);
            i++;
        }
        
        
        // case 2-> we have got the pos for new interval
        while(i < in.size() and in[i][0] <= ni[1]){
            ni[0] = min(in[i][0],ni[0]);
            ni[1] = max(in[i][1],ni[1]);
            i++;
        }
        
        ans.push_back(ni);
        
        // case 3 -> now put all in as it is
        
        while(i < in.size()){
            ans.push_back(in[i]);
            i++;
        }
        
        return ans;
        
        
    }
};