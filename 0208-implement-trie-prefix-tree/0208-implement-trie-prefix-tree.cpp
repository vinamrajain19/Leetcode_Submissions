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
    TrieNode * root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode * t = root;
        
        for(int i = 0;i<word.size();i++){
            
            int x = word[i] - 'a';
            
            if(t->children[x] == NULL){
                t->children[x] = new TrieNode();
            }
            
            t = t -> children[x];
        }
        
        t->endOfWord = true;
    }
    
    bool search(string word) {
         TrieNode * t = root;
        
        for(int i = 0;i<word.size();i++){
            
            int x = word[i] - 'a';
            
            if(t->children[x] == NULL){
                return false;
            }
            
            t = t -> children[x];
        }
        
        return t->endOfWord;
    }
    
    bool startsWith(string word) {
        TrieNode * t = root;
        
        for(int i = 0;i<word.size();i++){
            
            int x = word[i] - 'a';
            
            if(t->children[x] == NULL){
                return false;
            }
            
            t = t -> children[x];
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */