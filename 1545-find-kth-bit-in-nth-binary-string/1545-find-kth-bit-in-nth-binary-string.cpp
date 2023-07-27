class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }
    
    string exp(int n){
        if(n==0){
            return "0";
        }
        
        string s = exp(n-1);
        string sn = "";
        
        string r = invert(s);
        reverse(r.begin(),r.end());
        sn = s + "1" + r;
        
        return sn;  
        
    }
    
    char findKthBit(int n, int k) {
        return(exp(n)[k-1]);
    }
    
};