/* 
 Intuition
The idea is to use dynamic programming to calculate the number of ways to form the target string using the frequency of each character in each column of the matrix.

Approach
Calculate the frequency of each character in each column of the matrix using a 2D frequency array, then we'll pass the starting index of target srtring and index of column.
Then the conditions for base cases -

if index of string is greater than string size means the whole target string is finished and we got our solution (return 1 means we got our solution).
if column index is more than column size means we are out of reach return 0 in this case.
Now we'll calculate our answer as

we are taking the frequency of target string's char
and we are not taking the frequency then we will not move our target string's index
In this recursive solution the target string's and column's index are changing (only these two) we'll memoize accordingly

*/






class Solution {
public:
    
    int mod = 1e9+7;
    vector<vector<int>> fre;
    int dp[1001][1001];
    
    long f(vector<string> &words,string target,int i,int j){
        if(j == target.size()) return 1;
        
       if(i == words[0].size() || words[0].size() - i < target.size() - j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long  ans = f(words,target,i+1,j) % mod + (fre[i][target[j] - 'a']) * f(words,target,i+1,j+1) % mod;
        
        return dp[i][j] = ans % mod;
    }
    
    
    int numWays(vector<string>& words, string target) {
        fre.resize(words[0].size(),vector<int>(26,0));
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0;i<words.size();i++){
            for(int j = 0;j<words[0].size();j++){
                fre[j][words[i][j] - 'a']++;
            }
        }
        
        return f(words,target,0,0);
    }
};