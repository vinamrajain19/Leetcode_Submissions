//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        if(color == image[sr][sc]) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int nc = image[sr][sc];
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0;i<4;i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 or ny < 0 or nx >= image.size() or ny >= image[0].size() or image[nx][ny] != nc) continue;
                
                image[nx][ny] = color;
                q.push({nx,ny});
            }
        }
        
        image[sr][sc]= color;
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        return floodfill(image,sr,sc,newColor);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends