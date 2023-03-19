class Solution {
public:
    
    bool f(vector<int> &r,int c,long long m){
        long long x = 0;
        int n = r.size();
        long long car = 0;
        for(auto it : r){
            car += sqrt(m/it);
        }
        
        if(car >= c) return true;
        
        return false;
        
    }
    
    long long repairCars(vector<int>& r, int c) {
        long long ans = 0;
        
        int n = r.size();
        
        int mx = *max_element(r.begin(),r.end());
        
        long long s = 1;
        long long e = 1e18;
        
        
        while(s <= e){
            long long m = s+(e-s)/2;
            
            if(f(r,c,m)){
                ans = m;
                e = m-1;
            }
            else s = m +1;
        }
        return ans;
    }
};