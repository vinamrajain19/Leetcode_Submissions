class Solution {
public:
    
    string mx(string &a,string &b){
        int x = a.size();
        int y = b.size();
        
        if(a.find("0") != string::npos) return b;
        if(b.find("0") != string::npos) return a;
        
        
        if(x > y) return a;
        else if(y > x) return b;
        else{
            if(a > b) return a;
            else return b;
        }
    }
    
   
    string f(vector<int> &cost,int target,int idx,vector<vector<string>> &dp){
       
        if(target == 0){
            return "";
        }
        
        if(target < 0 or idx >= cost.size()) return "0";
        
        if(dp[idx][target] != "-1") return dp[idx][target];
        
        string a = to_string(idx+1) + f(cost,target-cost[idx],0,dp);  // include
        string b = f(cost,target,idx+1,dp);  // not include
        
        return dp[idx][target] = mx(a,b);
       
    }
    
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>> dp(cost.size()+1,vector<string>(target+1,"-1"));
        return f(cost,target,0,dp);   
    }
    
    
};