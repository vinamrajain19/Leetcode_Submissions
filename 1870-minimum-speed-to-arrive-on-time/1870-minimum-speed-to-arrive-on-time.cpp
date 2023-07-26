class Solution {
public:
    
    bool f(vector<int> &dist,double hour,int speed){
        
        double time = 0.0;
        
        for (int i = 0 ; i < dist.size(); i++) {
            
            double t = (double) dist[i] / (double) speed;
            
            time += (i == dist.size() - 1 ? t : ceil(t));
        }
        
        if(time <= hour) return true;
        return false;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        int e = 1e7;
        
        int ans = -1;
        
        while(s <= e){
            int m = s+(e-s)/2;
            
            if(f(dist,hour,m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        
        return ans;
    }
};