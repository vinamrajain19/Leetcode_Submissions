class Solution {
public:
    bool findWord(set<string>& mp , int i , string & str , int &cnt){
        if(i >= str.size() ){
            return true;
        }
        string temp = "";
        for(int j = i ; j < str.size() ; j++){
            temp += str[j];
            if(mp.find(temp) != mp.end()){
                //cout<<temp<<" : sub\n";
                cnt++;
                if(findWord(mp , j + 1 , str , cnt)){
                    return true;
                }
                cnt--;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& wd) {
        int n = wd.size();
        set<string> words;
        vector<string> ans;
        for(auto it : wd){
            words.insert(it);
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            string str = wd[i];
            int cnt = 0;
            if(findWord(words , 0 , str , cnt) && cnt >= 2){
                ans.push_back(str);
            }
        }
        return ans;
    }
};