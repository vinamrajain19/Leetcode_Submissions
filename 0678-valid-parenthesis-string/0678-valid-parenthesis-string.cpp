class Solution {
public:
    bool checkValidString(string s) {
        
        //stack of int as we are going to store indices of parenthesis and star 
        //as we have to check wheather string can be converted to valid string or not
        stack<int> open;
        stack<int> star;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                open.push(i);
            }
            else if(s[i] == '*')
            {
                star.push(i);
            }
            else //handle closing parenthesis
            {
                //if stack is empty and ')' comes means we are unable to balence the string
                //in that case we need to return false
                //but open stack is not empty, we can pop out to balance
                //open empty and star is not empty, we can use it to balance
                
                if(!open.empty())
                {
                    //open is not empty, remove corresponding open parenthesis
                    open.pop();
                }
                else if(!star.empty())
                {
                    //open empty star not empty, use star as a open parenthesis to balance
                    star.pop();
                }
                else
                {
                    //if both empty, there is no other way to balance it
                    return false;
                }
            }
        }
        
        
        //now process those leftover brackets if any 
        //once we have balanced closing  brackets, we need to handle opening brackets
        
        //till the opening parenthesis stack is not empty, as we need to balance it
        //if star stack isn't empty, it isn't a problem
        while(!open.empty())
        {
            //if open isn't empty but star is empty, how is we going to balance?
            //with help of star we are suppossed to balance it
            if(star.empty())
            {
                return false;
            }
            else if(open.top() < star.top())
            {
                //both stack will have elements in increasing order
                //if we have '*' after '(', we can make satr to ')', in order to balance '()'
                //but if we have '*' first and then '(', it is of no use 
                //as we cant make '*' to ')'  as its of no use we cant balance
                //and we leave '*' as empty, there would be leftover of '(' which makes string imbalance
                //so star stack top should greater than open stack top, its mendatory
                //thats the reason we have used indices in place of actual characters
                open.pop();
                star.pop();
            }
            else //open stack top is greater than star stack top, unable to balance
            {
                return false;
            }
            
        }
        
        //we reach here if everything is okay and just star stack is non empty or maybe its empty too
        return true;
        
    }

};