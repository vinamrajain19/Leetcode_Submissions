class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        
        int i = 0;
        int j = h.size()-1;
        
        while(i <= j){
            int a = min(h[i],h[j]) * (j-i);
            ans = max(ans,a);
            
            if(h[i] > h[j]) j--;
            else i++;
        }
        return ans;
    }
};