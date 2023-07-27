class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>v;
        v.push_back(1);
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
            {
                v.push_back(i);
                if(i*i!=n)
                    v.push_back(n/i);
            }
        }
        v.push_back(n);
        sort(v.begin(),v.end());
        if(k>v.size())
            return -1;
        return v[k-1];
    }
};