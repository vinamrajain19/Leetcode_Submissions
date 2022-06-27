class Solution {
public:
    int countBinarySubstrings(string s) {
       // convert -> '000011100011' -> '4-3-3-2' -> take min of every pair - > ans
        vector<int> v;
        int n = s.size();
        int c = 1;
        for(int i = 1;i<n;i++){
            if(s[i] == s[i-1]) c++;
            else{
                v.push_back(c);
                c = 1;
            }
        }
        v.push_back(c);
        
        int ans = 0;
        for(int  i = 0;i<v.size()-1;i++){
            ans += min(v[i],v[i+1]);
        }
        return ans;
    }
};