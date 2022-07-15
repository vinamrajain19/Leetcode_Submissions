class TrieNode{
    public:
    bool endOfWord;
    TrieNode* children[26];
    
    TrieNode()
    {
        endOfWord = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
        clear(root);
    }
    
    void clear(TrieNode* root)
    {
        for(int i = 0; i<26; i++)
        {
            if(root->children[i] != NULL)
            {
                clear(root->children[i]);
            }
        }
        
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL)
            {
                curr->children[index] = new TrieNode();
            }
            
            curr = curr->children[index];
        }
        
        curr->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL)
            {
                return false;
            }
            
            curr = curr->children[index];
        }
        
        return curr->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(int i = 0; i<prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            
            if(curr->children[index] == NULL)
            {
                return false;
            }
            
            curr = curr->children[index];
        }
        
        if(curr->endOfWord)
        {
            return true;
        }
        else
        {   
            for(int i = 0; i<26; i++)
            {
                if(curr->children[i] != NULL)
                {
                    return true;
                }
            }
            
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */