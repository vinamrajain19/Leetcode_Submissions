class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { 
		    return s;
	    }

	    string ans;
	    int periodSize = 2 * numRows - 2;

	    for(int i = 0; i < numRows; i++) {  
		    int in1 = periodSize - (i * 2);
		    int in2 = periodSize - in1;
		    int j = i;

		    while(j < s.length()) {
			    if (in1 != 0 && j < s.length()) { 
				    ans += s[j];
				    j += in1;
			    }

			    if (in2 != 0 && j < s.length()) {  
				    ans += s[j];
				    j += in2;
			    }   
		    }
	    }

	    return ans;
    }
};