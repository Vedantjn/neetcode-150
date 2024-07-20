class TrieNode{
    public:
        int is_EOS;
        TrieNode* children[26];

        TrieNode(){
            is_EOS=0;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};

class WordDictionary {
private: 
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {delete root;}
    
    void addWord(string word) {
        TrieNode* cur = root;
        int c;
        for(int i=0;i<word.length();i++){
            c = word[i]-'a';
            if(cur->children[c]==NULL){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->is_EOS = 1;
    }
    
    bool search(string word) {
        int c;
        TrieNode* cur = root;
        return search(root,word);
    }

    bool search(TrieNode* root,string word){
        TrieNode* cur = root;
        int c;
        for(int i=0;i<word.length();i++){
            c=word[i]-'a';
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(cur->children[j] && search(cur->children[j],word.substr(i+1))){
                        return true;
                    }
                }
                return false;
            }else{
                cur=cur->children[c];
                if(cur == NULL)
                    return false;
            }
        }
        return cur->is_EOS;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */