class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int> &vis,int i){
        vis[i] = true;
        for(auto it : rooms[i]){
            if(vis[it] != 1){
                dfs(rooms,vis,it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        dfs(rooms,vis,0);
        for(int i = 0;i<vis.size();i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
};