class Solution {
public:
    bool f(vector<int> &w,int days,int val){
        int c = 0;
        int ans = 1;
        int i = 0;
        while(i<w.size()){
           if(w[i] > val) return false;
           if(c + w[i] <= val){
               c += w[i];
           }
           else{
               ans++;
               c = w[i];
           }
           i++;
        }
        
        if(ans <= days) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& w, int days) {
        int sum = 0;
        for(auto it : w) sum += it;
        
        int s = 1;
        int ans = 0;
        int e = sum;
        
        while(s<=e){
            int m = (s+e)/2;
            if(f(w,days,m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        return ans;
    }
};