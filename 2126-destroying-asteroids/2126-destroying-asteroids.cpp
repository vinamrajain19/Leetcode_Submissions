
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        long long x = mass;
        sort(a.begin(),a.end());
        for(int i = 0;i<a.size();i++){
            if(x < a[i]) return false;
            else{
                x += a[i];
            }
        }
        return true;
    }
};