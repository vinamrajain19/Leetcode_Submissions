class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        if(f.size() == 1 and n > 1){
            return false;
        }
        
        if(f.size() == 1 and n == 1) return f[0] == 0;
        
        for(int i = 0;i<f.size();i++){
            
            if(i == 0){
                if(n > 0 and f[i] == 0 and i+1 < f.size() and f[i+1] == 0) f[i] = 1,n--;
            }
            
            else if(i == f.size()-1){
                if(n> 0 and f[i] == 0 and i-1 >= 0 and f[i-1] == 0) f[i] = 1,n--;
            }
            
            else{
                if(n){
                    if(f[i] == 0){
                        if(i-1 >= 0 and f[i-1] == 0){
                            if(i+1 < f.size() and f[i+1] == 0) {
                                f[i] = 1;
                                n--;
                            }
                        }
                    }
                }
            }
        }
        
        return n == 0;
    }
};