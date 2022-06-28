class Solution {
public:
    //those nodes which have ind = 0 -> can be the ans -> beacause we cant reach to these nodes from other nodes
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ind(n,0);
        for(int i = 0;i<edges.size();i++){
            ind[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(ind[i] == 0)
             ans.push_back(i);
        }
        return ans;
        
    }
};