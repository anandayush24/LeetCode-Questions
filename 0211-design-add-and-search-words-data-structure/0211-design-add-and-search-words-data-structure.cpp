class Trie{
    public:
        char ch;
        Trie* childs[26];
        bool isEnd;
        Trie(char ch){
            this->ch = ch, this->isEnd = false;
            for(int i=0;i<26;i++) childs[i] = NULL;
        }
};

class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
        root = new Trie('0');
    }
    
    void addWord(string word) {
        auto node = root;
        for(auto &ch : word){
            if( node->childs[ch-'a'] == NULL ){
                auto newNode = new Trie(ch);
                node->childs[ch-'a'] = newNode;
            }
            node = node->childs[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string &word, int index, Trie* node){
        if( index >= word.size() ){
            return node->isEnd;
        }
        
        char ch = word[index];
        if( ch == '.' ){
            for(int i=0;i<26;i++){
                if( node->childs[i] && searchHelper(word, index+1, node->childs[i]) ){
                    return true;
                }
            }
        }
        else{
            if( node->childs[ch-'a'] ){
                return searchHelper(word, index+1, node->childs[ch-'a']);
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */