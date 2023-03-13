//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool check(int grid[N][N],int k,int i,int j){
        for(int id = 0;id<9;id++){
            if(grid[id][j] == k) return false;
            if(grid[i][id] == k) return false;
        }
        
        int row = i - i % 3;
        int col = j - j % 3;

        for(int p = row;p < row + 3;p++){
            for(int q = col;q< col + 3;q++){
                if(grid[p][q] == k) return false;
            }
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(grid[i][j] == 0){
                    for(int k = 1;k<=9;k++){
                        if(check(grid,k,i,j)){
                            grid[i][j] = k;
                            if(SolveSudoku(grid)) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
                
            }
        }
        
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        SolveSudoku(grid);
        
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends