class Solution {
public:
    
    void makelps(string &s,vector<int> &lps){
        int i = 0;
        int j = 1;
        
        while(j < s.size()){
            if(s[i] == s[j]){
                lps[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i != 0){
                   i = lps[i-1];
                }
                else j++;
            }
        }
    }
    
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        vector<int> lps(b.size(),0);
        makelps(b,lps);
        
        int i = 0;
        int j = 0;
        
        while(i < n){
            
            if(j < m and a[(i+j) % n] == b[j]){
                j++;
            }
            
            if(j == m){
                if((i+j) % n){
                    return (i+j)/n+1;
                }
                 
                return (i+j)/n;
            }
            
            else if(i < n and a[(i+j) % n] != b[j]){
                if(j != 0){
                    i += j-lps[j-1];
                    j = lps[j-1];
                }
                else i++;
            }
        }
        
        return -1;
    }
};