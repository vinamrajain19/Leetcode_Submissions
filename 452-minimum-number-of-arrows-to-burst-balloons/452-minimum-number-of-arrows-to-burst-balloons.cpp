bool comp(vector<int> &x, vector<int> &y){
    return x[1] < y[1];
}
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int ans = 1;
        int free = points[0][1];
        for(int  i = 1;i<points.size();i++){
            if(free < points[i][0]){
                ans++;
                free = points[i][1];
            }
        }
        return  ans;
    }
};