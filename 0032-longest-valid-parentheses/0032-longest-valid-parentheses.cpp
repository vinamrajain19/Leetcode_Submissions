/* 
The workflow of the solution is as below.

Scan the string from beginning to end.
If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.
After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.
If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3. */



class Solution {
public:
    int longestValidParentheses(string s) {
        
        int size = s.size(), res = 0;
        if(size < 2) return res;
        stack<int> si;
        for(int i = 0; i < size; ++i) {
            if('(' == s[i]) si.push(i);
            else {
                if(si.empty()) si.push(i);
                else {
                    if(s[si.top()] == '(') {
                        si.pop();
                        res = max(i - (si.empty()? -1: si.top()), res);
                    }
                    else si.push(i);
                }
            }
        }
        return res;
    }

};