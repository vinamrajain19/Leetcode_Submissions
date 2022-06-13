class Solution {
public:
    static bool comp(vector<int> &x,vector<int> &y){
        return x[1] < y[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        
        sort(in.begin(),in.end(),comp);
        int len = 1;
        int last = in[0][1];
        
        for(int i = 1;i<in.size();i++){
            
            if(in[i][0] >= last){
                len++;
                last = in[i][1];
            }
        }
        return in.size() - len;
    }
};