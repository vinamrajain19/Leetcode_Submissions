class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for(int i = 0;i<201;i++){
            for(int j = 0;j<201;j++){
                for(int k = 0;k<circles.size();k++){
                    int x = circles[k][0];
                    int y = circles[k][1];
                    int r = circles[k][2];
                    if((x-i) * (x-i) + (y-j) * (y-j) <= r*r){
                       ans++;
                       break;
                    } 
                }
            }
        }
        return ans;
    }
};