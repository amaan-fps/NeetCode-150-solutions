class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word_end = false;
};

class Trie {
private:
    TrieNode root;
public:
    Trie() {
        root = TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = &root;
        for(char c : word)
        {
            if(curr->children[c] == NULL)
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->word_end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = &root;
        for(char c : word)
        {
            if(curr->children[c] == NULL)
                return false;
            curr = curr->children[c];
        }
        return curr->word_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = &root;
        for(char c : prefix)
        {
            if(curr->children[c] == NULL)
                return false;
            curr = curr->children[c];
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
