class Solution {
public:
    
    // min no of steps -> use BFS when we use grpah ,tree or matrix
    
    vector<int> findcordinates(int new_curr,int n){
            int r=n-(new_curr-1)/n-1;
        
            int c=(new_curr-1)%n;
        
            if(r%2==n%2){
                return {r,n-1-c};
            }
            else{
                return {r,c};
            }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        queue<int> q;
        q.push(1);
        vis[n-1][0] = 1;
        
        int steps = 0;
        
        while(q.size()){
            int x = q.size();
            
            while(x--){
                int curr = q.front();
                q.pop();
                
                if(curr == n*n) return steps;
                
                for(int i = 1;i<=6;i++){
                    int new_curr = curr+i;
                    
                    if(new_curr > n*n) break;
                    
                    vector<int> pos = findcordinates(new_curr,n);
                    
                    if(vis[pos[0]][pos[1]] == 0){
                        vis[pos[0]][pos[1]] = 1;
                        if(board[pos[0]][pos[1]] == -1) q.push(new_curr);
                        else q.push(board[pos[0]][pos[1]]);
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};