class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;
        int ans=0;
        int i=0;//Left Pointer
        int n=s.length();
        unordered_map<char,long long>m;
        for(int j=0;j<n;j++){
           m[s[j]]++;//Adding element to map
            while(m.size()>1&&i<j){//Window is Invalid when map contains more then 1 element, We increase left Pointer
                m[s[i]]--;//Removing the element
                if(m[s[i]]==0)//Removing the element from map when count becomes zero
                    m.erase(s[i]);              
                i++;//Incrementing the left pointer
            }   
          //  cout<<m[s[j]]<<" ";
            ans=(ans+m[s[j]])%mod;//Counting
        }
       
        return ans;
    }
};