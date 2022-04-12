class Solution {
public:
    int t[2001][2001];
    
    
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int mcm(string &s,int i,int j){
        if(i>=j) return 0;
        
        if(ispalindrome(s,i,j)) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int mn = INT_MAX;
        for(int k = i;k <= j-1;k++){
            if(ispalindrome(s,i,k)){
                int temp = 1 + mcm(s,k+1,j);
                mn = min(mn,temp);
            }
            
        }
        
        return t[i][j] = mn;
    }
    


    int minCut(string s) {
        memset(t,-1,sizeof(t));
        int n = s.size();
        return mcm(s,0,n-1);
    }
};