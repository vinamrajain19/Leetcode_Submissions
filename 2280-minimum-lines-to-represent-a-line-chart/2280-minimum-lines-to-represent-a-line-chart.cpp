class Solution {
public:

    int minimumLines(vector<vector<int>>& s) {
        if(s.size() == 1) return 0;
        
        int ans = 1;
        int n = s.size();
        sort(s.begin(),s.end());
        for(int i = 0 ;i<n-2;i++){
            int  y1 = (s[i+1][1] - s[i][1]);
            int  x1 = (s[i+1][0] - s[i][0]);
            
            int y2 = (s[i+2][1] - s[i+1][1]);
            int x2 = (s[i+2][0] - s[i+1][0]);
            
            if((long)y1 * x2 != (long)y2 * x1) ans++;
        }
        return ans; 
    }
};