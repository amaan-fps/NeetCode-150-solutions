class wordNode {
public:
    unordered_map<char, wordNode*> children;
    bool word_end = false;
};

class WordDictionary {
private:
    wordNode* root;
public:
    WordDictionary() {
        root = new wordNode();
    }
    
    void addWord(string word) {
        wordNode* curr = root;
        for(char c : word)
        {
            if(curr->children[c] == NULL)
                curr->children[c] = new wordNode();
            curr = curr->children[c];
        }
        curr->word_end = true;
    }
    
    bool dfs(wordNode* root, int j, string& word)
    {
        wordNode* curr = root;

        int size = word.size();
        for(int i = j; i < size; i++)
        {
            char c = word[i];
            if(c == '.')
            {
                for(auto child : curr->children)
                    if(child.second && dfs(child.second, i+1, word))
                        return true;
                return false;
            }
            else
            {
                if(curr->children[c] == NULL)
                    return false;
                curr = curr->children[c];
            }
        }
        return curr->word_end;
    }

    bool search(string word) {
        return dfs(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
