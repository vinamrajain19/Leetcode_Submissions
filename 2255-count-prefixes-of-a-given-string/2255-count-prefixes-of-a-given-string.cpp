class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(int i = 0;i<words.size();i++){
            string t = words[i];
            string x = "";
            for(int j = 0 ;j<s.size();j++){
                x += s[j];
                if(x == t){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};