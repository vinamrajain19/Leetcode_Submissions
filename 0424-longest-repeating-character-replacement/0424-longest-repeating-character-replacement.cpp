class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
         int ans=0;
        for(int x=0;x<26;x++)
        {
            int i=0,j=0;
            int cnt=0;
            int len=k;
            char c = char('A'+x);
            while(j<n)
            {
                if(s[j]!=c)
                {
                    cnt++;
                    len--;
                }
                if(len<0)
                {
                    while(len<0 && i<j)
                    {
                        if(s[i]!=c)
                        {
                            len++;
                            cnt--;
                        }
                        i++;
                    }
                }
                else
                {
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};