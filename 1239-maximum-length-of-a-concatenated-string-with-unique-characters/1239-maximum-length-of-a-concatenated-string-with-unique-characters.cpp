class Solution {
public:
    int maxi = 0;
    
    bool is(string& str)
    {
        int n = str.size();
        
        vector<int> mp(26, 0);
        
        for(int i = 0; i < n; i++)
        {
            mp[str[i] - 'a']++;
            
            if(mp[str[i] - 'a'] > 1)
                return false;
        }
        
        return true;
    }
    
    void f(vector<string>& arr, int i, int n, string curr)
    {
        
        if(is(curr) == false)
            return;
        
        // base case
        
        if(i == n)
        {
            maxi = max(maxi,(int)curr.size());
            return;
        }
        
        // we have two options either include the curr string or exclude
        // include the curr string
        
        f(arr, i + 1, n, curr + arr[i]);
        // exclude the curr string
        f(arr, i + 1, n, curr);
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        
        f(arr, 0, n, "");
        
        return maxi;
    }
};