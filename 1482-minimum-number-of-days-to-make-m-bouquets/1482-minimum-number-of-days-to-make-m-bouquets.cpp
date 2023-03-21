class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int s = 1;
        int e = *max_element(b.begin(),b.end());
        
       // if(b.size() < m*k) return -1;
        
        int ans = -1;
        
        while(s <= e){
            int mid = s+(e-s)/2;
            
            int boq = 0;
            int cnt = 0;
            
            for(int i = 0;i<b.size();i++){
                if(b[i] <= mid){
                    cnt++;
                }
                else cnt = 0;
                
                if(cnt == k){
                    boq++;
                    cnt = 0;
                }
            }
            
            
            if(boq >= m){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
            
        }
        
        return ans;
    }
};