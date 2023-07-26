class Solution {
public:
   
    
   int maxScore(vector<int>& c, int k) {
        int n = c.size();
        int sz = n - k;
        int to = accumulate(c.begin(),c.end(),0);
        
        if(k == n) return to;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        int mn = to;
        while(j<n){
            sum += c[j];
            if(j-i+1 < sz){
                j++;
            }
            else if(j-i+1 == sz){
                mn = min(mn,sum);
                sum -= c[i];
                i++;
                j++;
            }
        }
        
        return to - mn;
        
    }
};