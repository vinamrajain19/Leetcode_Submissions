class Solution {
public:
    
    bool f(long long m,vector<int> &time,int t){
        long long x = 0;
        
        for(int i = 0;i<time.size();i++){
            x += (m/time[i]);
        }
        
        if(x >= t) return true;
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s = 1;
        long long e = 1e14;
        
        while(s < e){
            
            long long m = (s+e)/2;
            
            if(f(m,time,totalTrips)){
                e = m;
            }
            else s = m+1;
            
        }
        
        return s;
        
    }
};