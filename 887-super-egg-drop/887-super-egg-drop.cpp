class Solution {
public:
     int t[101][10001];
     int solve(int e,int f){
        if(f == 0 or f == 1 or e == 1) return f;
        
        
        if(t[e][f] != -1){
            return t[e][f];
        }
        
        int mn = INT_MAX;
        
        int l = 1;
        int h = f;
         while(l<=h){
             // check worst case thats why max
           // if egg breaks then egg-1 and floor till kth floor
           // if it doesn't break then egg and floor above k (floor-k) would be 1st floor for next recursion
             int mid = l+(h-l)/2;
             int left,right;
             if(t[e-1][mid-1]!=-1){
                 left = t[e-1][mid-1];
             }
             else{
                 left = solve(e-1,mid-1);
                 t[e-1][mid-1] = left;
             }
             
             if(t[e][f-mid] != -1){
                 right = t[e][f-mid];
             }
             else{
                 right = solve(e,f-mid);
                 t[e][f-mid] = right;
             }
             
             int temp = 1 + max(left,right);
             mn = min(mn,temp);
             
             if(right > left){
                 l = mid+1;
             }
             else{
                 h = mid-1;
             }
         }
        
        return t[e][f] = mn;
    }
    
    int superEggDrop(int e, int f) {
        memset(t,-1,sizeof(t));
        return solve(e,f);
    }
};