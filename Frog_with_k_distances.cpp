#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    
    //dp[i] denotes the minimum cost to reach ith stone
    // 0 < i < n - 1 are the stones
    //We are asked to dind the cost to reach last stone i.e dp[n - 1]
    //Initially there is infinite cost to reach ith stones
    vector<int> dp(n, INT_MAX);
  
    //To reach first stone there is no cost. SO dp[0] = 0
    dp[0] = 0;
   //To reach second stone the frog can jump from 0th stone costing dp[1] = abs(h[1] - h[0])
    dp[1] = abs(h[1] - h[0]);
    
    //For every other stones 2 <= i < n, the frog can jump from the (i - 1), (i - 2)...(i - k)th stones 
    for(int i = 2; i < n; i++){
      for(int j = i - 1, jump = 0; j  >= 0 && jump < k; j--, jump++){
        dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
      }
    }
    //Print minm cost to reach (n - 1)th stone
    cout << dp[n - 1];
    return 0;
}
