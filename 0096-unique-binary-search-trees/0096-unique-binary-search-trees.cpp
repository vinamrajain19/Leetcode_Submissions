class Solution {
public:
    
    /* Problem is to find the no. of BSTs that are possible for given n: no. of nodes in BST. To solve this recursively, we need to build a recurrance relation [Inductive Hypothesis] and a base case.
Let C(n) := no. of unique BSTs possible with n no. of nodes where n >= 0
Clearly, a null node and a single node, both are BSTs (only 1 unique BST for each). So, we have got our base case i.e C(0) = C(1) = 1 orC(n) = 1 when n <= 1.
Now, Let's break n nodes of BST into 1, i - 1, and n - i nodes, where, 1 node is given to root, i - 1 nodes are given to left BST subtree and n - i nodes are given to right BST subtree respectively s.t overall we still have 1 + i - 1 + n - i = n nodes. Cleary here, 1 <= i <= n as both left and right BST subtrees can have: atleast 0 and atmost n - 1 nodes. */
    
    
    int dp[20];
    int f(int n){
        if(n == 0 or n == 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += f(i-1) * f(n-i);
        }
        
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};