class Solution {
public:
    int mod=1e9+7;
    
    int dp[100001];
    
    int helper(int i, string &s){
        if(i==s.size()) return 1;
        if(s[i]=='0'||i>s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int count=0;
        // Considering Single character
        if(s[i]=='*'){
            count=count+(9L*helper(i+1,s))%mod; // * ranges from 1-9
        }
        else{
            count=count+(1L*helper(i+1,s))%mod; // if any number is present it is considered as single way and we proceed further
        }
        // Considering Two characters
        if(s[i]=='1'){
            if(i+1<=s.size()-1){
                if(s[i+1]=='*'){
                    count=count+(9L*helper(i+2,s))%mod; // if we suppose current value as 1 and next character is * then we have 9 different ways to proceed ranging from 11 to 19
                }
                else if(s[i+1]>='0'&&s[i+1]<='9'){
                    count=count+(1L*helper(i+2,s))%mod; // if any number is present then we consider these two numbers collectively and consider it as 1 way and proceed 
                }
            }
        }
        else if(s[i]=='2'){
            if(i+1<=s.size()-1){
                if(s[i+1]=='*'){
                    count=count+(6L*helper(i+2,s))%mod; // the range is only from 21 - 26, so we consider these 6 ways and proceed
                }
                else if(s[i+1]>='0'&&s[i+1]<='6'){
                    count=count+(1L*helper(i+2,s))%mod; // if we have any number present then we collectively think it as a single number and proceed
                }
            }
        }
        else if(s[i]=='*'){
            if(i+1<=s.size()-1){
                if(s[i+1]=='*'){
                    count=count+(15L*helper(i+2,s))%mod; //if we consider "**" then it ranges ferom 11 - 26, so we consider these 15 ways and proceed
                }
                else if(s[i+1]>='0'&&s[i+1]<='6'){
                    count=count+(2L*helper(i+2,s))%mod; // if we consider "*_" ( _ indictes any number) we have only two possibilities of 1 and 2 at "*" position.
                }
                else if(s[i+1]>'6'){
                    count=count+(1L*helper(i+2,s))%mod; // same as the above case if the next number value is higher than 6, then we can consider only 1. 
                }
            }
        }
        return dp[i]=count%mod;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(0,s)%mod;
    }
};