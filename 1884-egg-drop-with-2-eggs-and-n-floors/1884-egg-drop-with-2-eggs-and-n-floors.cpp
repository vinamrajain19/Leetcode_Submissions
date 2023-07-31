class Solution {
public:
    int dp[1001][3];
    int solve(int floor, int egg) {
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;
        if(dp[floor][egg] != -1) return dp[floor][egg];
        int mi = INT_MAX, l = 1, r = floor;
        while(l < r){
            int mid = l + (r - l) / 2;
            
            int left = solve(mid - 1, egg - 1); //egg broken check for down floors of mid.
            
            int right = solve(floor - mid, egg); // not broken check for up floors of mid.
            
            if(left >= right) {   //left >= right so we will go downward
                r = mid;
            } else { //since right is more than left and we need more in worst case 
                l = mid + 1;  // so l=mid+1 to gain more  for worst case : upward
            }
            mi = min(mi, 1+max(left, right)); //store minimum attempts of (max of both left, right )
        }
        return dp[floor][egg] = mi;
    }
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 2);
    }
};