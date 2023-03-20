class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int s = 1;
        int e = *max_element(p.begin(),p.end());
       

        while(s<e){
            int m = (s+e)/2;
            
            int x = 0;
            for(int i= 0;i<p.size();i++){
                x += (p[i]/m);
                if(p[i]%m) x++;
            }
            
            
            if(x <= h){
                e = m;
            }
            else s = m+1;
        }
        return s;      
    }
};