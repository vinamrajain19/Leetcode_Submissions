//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    unordered_map<string, int> mpp;

    // A vector for storing the final answer.
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string> &seq)
    {
        // Function for implementing backtracking using the created map
        // in reverse order to find the transformation sequence in less time.

        // Base condition :
        // If word equals beginWord, we’ve found one of the sequences
        // simply reverse the sequence and return. 
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
    
            // reverse again so that the dfs calls are not disturbed.
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word];

        // Replace each character of the word with letters from a-z 
        // and check whether the transformed word is present in the map
        // and at the previous level or not.  
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    // pop the current word from the back of the queue
                    // to traverse other possibilities.
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Perform BFS traversal and push the string in the queue
        // as soon as they’re found in the wordList.
        queue<string> q;
        b = beginWord;
        q.push({beginWord});

        // beginWord initialised with level 1.
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty())
        {

            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            // Break out if the word matches the endWord
            if (word == endWord)
                break;

            // Replace each character of the word with letters from a-z 
            // and check whether the transformed word is present in the 
            // wordList or not, if yes then push to queue
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {

                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                       
                        // push the word along with its level
                        // in the map data structure.
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
    
        // If we reach the endWord, we stop and move to step-2
        // that is to perform reverse dfs traversal.
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
    
public:
    vector<vector<string>> findSequences(string b, string e, vector<string>& w) {
        // code here
        return findLadders(b,e,w);
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends