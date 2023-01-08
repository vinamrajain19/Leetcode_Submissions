class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        if(p.size() == 1) return 1;
        
        unordered_map<double,int> m;
        
        int ans = 0;
        int temp = 0;
        for(int i = 0;i<p.size();i++){
            m.clear();
            for(int j = i+1;j<p.size();j++){
                
                double slope = 0.0;
                
                if(p[i][0] == p[j][0]){
                    slope = 1e9;
                    m[1e9]++;
                }
                else {
                    slope = (double)(p[j][1] - p[i][1])/(p[j][0] - p[i][0]);
                    m[slope]++;
                    cout<<slope<<" ";
                }
                
                temp = max(temp,m[slope]);
            }
            ans= max(ans,temp);
        }
        
        return ans+1;
    }
};