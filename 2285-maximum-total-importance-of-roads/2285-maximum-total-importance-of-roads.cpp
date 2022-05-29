class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //find indegree
        vector<long long> in(n,0);
        for(auto it : roads){
            in[it[0]]++;
            in[it[1]]++;
        }
        //sort
        sort(in.rbegin(),in.rend());
        
        //greedy -> which node -> has max in -> got max imp -> n and next got n-1 and so on till 1
        long long sum = 0;
        for(int i = 0;i<in.size();i++){
            sum += in[i] * n;
            n--;
        }
        return sum;
        
    }
};