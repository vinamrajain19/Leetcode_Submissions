class Solution {
public:
    
    bool f(long b){
        long s = 0;
        long e = b;
        
        while(s <= e){
            long m = s+(e-s)/2;
            
            long x = m*m;
            
            if(x == b) return true;
            else if(x > b) e = m-1;
            else s = m+1;
        }
        
        return false;
    }
    
    bool judgeSquareSum(int c) {
        for(long a = 0;a*a <= c;a++){
            long b = c - (a*a);
            if(f(b)) return true;
        }
        
        return false;
    }
};