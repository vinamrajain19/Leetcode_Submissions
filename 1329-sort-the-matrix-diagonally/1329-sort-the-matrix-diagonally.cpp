class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       unordered_map<int,priority_queue<int,vector<int>,greater<int>>> map;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                map[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
			    //adding values from the map into the matrix, and removing them from map.
                mat[i][j]=map[i-j].top();
                map[i-j].pop();
            }
        }
        return mat;
    }
};