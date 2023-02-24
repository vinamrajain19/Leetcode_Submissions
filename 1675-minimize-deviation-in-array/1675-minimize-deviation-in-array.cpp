class Solution {
public:
    
    // Make all odd values even

    // Take minimum of all values

    // Find Max & difference & update max/2, till the max is even

    // Otherwise difference is the result
    
    

    int minimumDeviation(vector<int>& arr) {
        int n = arr.size(); // extracting size of the array
        
        for(int i = 0; i < n; i++) // making every odd element to even
        {
            if(arr[i] % 2 == 1) // if it is odd
            {
                arr[i] = 2 * arr[i]; // multiply it by 2
            }
        }
        
        int mn = *min_element(arr.begin(), arr.end()); // take minimum element from array
        int mx = *max_element(arr.begin(), arr.end());// take maximum element from array
        
        int ans = mx - mn; // intially answer is difference of these two
        
        priority_queue<int> maxh; // creating max heap
        
        for(int i = 0; i < n; i++) // push every element to max heap
        {
            maxh.push(arr[i]);
        }
        
        // Until our top element is even, we will run the loop
        while(maxh.top() % 2 == 0) 
        {
            int top = maxh.top(); // extracting top of the heap
            maxh.pop(); // pop that elemet from heap
            
            ans = min(ans, top - mn); // update answer to minimum difference
            
            top = top / 2; // divide by 2 to our top
            
            mn = min(mn, top); // also update minimum element as well
            
            maxh.push(top); // push update top element to again heap
        }
        
        // again update the answer with one more time, because when we will stop 
        // we stop when we find an odd element on the top, so chaeck the difference
        // with this also and update it to the answer
        ans = min(ans, maxh.top() - mn); 
        
        return ans; // and at last return the answer
    }
};