class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        prev[0] = 0; 
        
        for(int j = 0;j<=n;j++){
            prev[j] = 0;
        }
        
        //main code
        for(int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = text1[i-1] + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        
        int f = 0;
        for(int i = 0;i<m;i++){
            f += text1[i];
        }
        
        int s = 0;
        for(int i = 0;i<n;i++){
            s += text2[i];
        }
        
        return f - prev[n] + s - prev[n];
    }
};