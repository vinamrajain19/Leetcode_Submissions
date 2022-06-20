class Solution {
public:
    static bool comp(string&a,string&b){
        return a.size() > b.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
            sort(words.begin(),words.end(),comp);
        string res = "";
            for(int i = 0 ;i<words.size();i++)
            {
                string temp =  words[i] + '#';
                if(res.find(temp) == string::npos){
                    res += temp;
                }
                else continue;
            }        
        return res.size();
    }
};