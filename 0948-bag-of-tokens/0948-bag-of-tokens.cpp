class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        
        sort(t.begin(),t.end());
        int i =0;
        int j = t.size()-1;
        
        int ans = 0;
        int mx = 0;
        while(i<=j){
            if(t[i] <= p){
                ans++;
                p -= t[i];
                i++;
                mx = max(mx,ans);
            }
            else if(ans >= 1){
                p += t[j];
                ans--;
                j--;
            }
            else break;
            
        }
        
        if(mx == -1e9) return 0;
        return mx;
        
    }
};