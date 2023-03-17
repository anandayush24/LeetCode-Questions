struct TrieNode 
{
    char c;
    bool isWord;
    vector<TrieNode*> children;

    TrieNode(char x)
    {
        c = x;
        isWord = false;
        children.resize(26, nullptr);
    }
};

class Trie 
{
    TrieNode *root;
public:
    Trie() 
    {
        root = new TrieNode('*');
    }
    
    void insert(string word) 
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (curr->children[word[i] - 'a'] == nullptr)
                curr->children[word[i] - 'a'] = new TrieNode(word[i]);
            curr = curr->children[word[i] - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) 
    {
        TrieNode *r = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (r->children[word[i] - 'a'] == nullptr)
                return false;
            else
                r = r->children[word[i] - 'a'];
        }
        return r->isWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode *r = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (r->children[prefix[i] - 'a'] == nullptr)
                return false;
            else
                r = r->children[prefix[i] - 'a'];
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