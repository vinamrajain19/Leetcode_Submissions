class Solution {
public:
    int lcs(string text1, string text2) {
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
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return prev[n];
        
    }
    
    int minDistance(string word1, string word2) {
        int LCS = lcs(word1,word2);
        int deletion = word1.size() - LCS;
        int insertion = word2.size() - LCS;
        
        return deletion + insertion;
    }
};