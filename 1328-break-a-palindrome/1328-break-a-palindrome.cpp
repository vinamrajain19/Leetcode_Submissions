class Solution {
public:
    
    
    string breakPalindrome(string p) {
        if(p.size() == 1) return "";
        
        int f = 0;
        for(int i = 0;i<p.size()/2;i++){
            if(p[i] != 'a'){
                p[i] = 'a';
                f = 1;
                break;
            }
        }
    
        
        if(f == 0){
            p[p.size()-1] = 'b';
        }
        return p;
    }
};