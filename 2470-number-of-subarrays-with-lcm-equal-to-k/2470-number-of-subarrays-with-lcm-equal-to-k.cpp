class Solution {
public:
   
    #define ll unsigned int
    ll lcm(ll a, ll b){
        return (a / gcd(a, b)) * b;
    }
    
    int subarrayLCM(vector<int>& arr, int k) {
           ll n = arr.size();
           ll c= 0;
         for(ll i=0; i<n; i++)
         {
             ll curr = arr[i];
             for(ll j=i; j<n; j++)
             {
                 curr = lcm(curr,arr[j]);
                 if(curr==k) c++;
                 if(curr>k)break;
             }
         }
        return c;
      
    }
  
};