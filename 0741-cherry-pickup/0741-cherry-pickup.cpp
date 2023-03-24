class Solution {
public:
    
    /* Now, we know that we want collectively maximum cherries.
So, we have to do the traversal of both paths at the same time and select maximum global answer. 
The potential problem of this approach is double counting (if we collect same cherry in 2 paths), but this can be easily avoided in code.
If both are at the same cell we count cherry only once.
Following code is backtracking brute force so it is TLE.
Time Complexity is : 4^N*N. As we are calling cherryPickup 4 times recursively with problem size N*N.
*/

    
    /*
explanation:

-> since we have to first reach the bottom right cell and then again reach the upwards            starting cell instead we can start both from the start taking differnt paths.

-> first from start there can be only two probalities of moving either moving downwards or        moving right thus at max only two people or cherry collectors are possoble together.

-> to maximise the profit at each step will always check which path will get most profit        either moving down or right for both people.

-> since every time one will move either downwards or towards right ,sum of x and y              coordinates of each person will be equal i.e x1+y1=x2+y2

-> on each step there will be only 4 possiblites :
   1. either both move vertically down
   2. either both move right
   3. either one move down and other right
   4. either one move right and other down.
   
-> to reduce time we will use memiosation to save prevoisly visited coordinates.

-> (r1,c1) coordinates for first person and (r2,c2) for second.

*/

    int dp[50][50][50];
    
    int check(int r1,int c1,int r2,int n,vector<vector<int>>&grid){
            int c2=r1+c1-r2;  //r1+c1==r2+c2 => c2=r1+c1-r2;
        
        
            if(r1>=n or c1>=n or r2>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1)
              return INT_MIN; //return a false value if base case fails.
        

           if(dp[r1][c1][r2]!=-1) 
             return dp[r1][c1][r2] ; //use of memoisation to record already calculated values

          //if one can reach the end then other can also reach the end.
          if(r1==n-1 and c1==n-1)  return grid[r1][c1];

          int temp=0;

          if(r1==r2 and c1==c2) //if both are on the same cell then only one will collect the 
                                 //cherry both can't collect the same cherry.
            temp+=grid[r1][c1];


          else temp+=grid[r1][c1]+grid[r2][c2]; //both cherries will be added to the total

          int a=check(r1+1,c1,r2+1,n,grid); //both move vertically
          int b=check(r1+1,c1,r2,n,grid);     
          int c=check(r1,c1+1,r2,n,grid);          
          int d=check(r1,c1+1,r2+1,n,grid);         

          temp+=max(max(a,b),max(c,d)); //max of a,b,c,d
          
          return dp[r1][c1][r2]=temp; //saving the current result
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,check(0,0,0,n,grid));
    }
};