class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int>&b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),cmp);
        int ans = 0;
        int last = in[0][1];
        
        for(int i = 1;i<in.size();i++){
            if(last > in[i][0]){
                ans++;
            }else{
                last = in[i][1];
            }
        }
        
        return ans;
    }
};