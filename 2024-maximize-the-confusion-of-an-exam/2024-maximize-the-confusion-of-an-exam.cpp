class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0 , j = 0 , nT = 0 , nF = 0 , n = answerKey.size() , len = 0;
        
        while(j<n)
        {
            answerKey[j]=='T'?nT++:nF++;
			//minimum among T and F
            int count = min(nT,nF);
            
			//update the length if condition holds good
            if(count<=k)
                len = max(len , j-i+1);
            else{
			   //shrink the window
                while(count>k)
                {
                    answerKey[i]=='T'?nT--:nF--;
                    count = min(nT,nF);
                    i++;
                }
            }
            j++;
        }
        return len;
    }

};