class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> m;
        char c = 'a';
        for(int i = 0;i<key.size();i++){
            if(m.find(key[i]) == m.end() and key[i] != ' '){
                m[key[i]] = c++;
            }
        }
        
        string ans = "";
        for(int i = 0;i<message.size();i++){
            if(message[i] == ' '){
                ans += " ";
            }
            else{
                ans += m[message[i]];
            }
        }
        return ans;
    }
};