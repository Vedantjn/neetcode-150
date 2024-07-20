/*
    Implement trie (store/retrieve keys in dataset of strings)

    Each node contains pointer to next letter & is word flag

    Time: O(n) insert, O(n) search, O(n) startsWith
    Space: O(n) insert, O(1) search, O(1) startsWith
*/

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < prefix.size(); i++) {
            curr = prefix[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */




class Trie {
public:
 unordered_map<string, int>wordcount; // to store the count of words
 unordered_map<char, vector<string>>words; // to store strings

    Trie() {
        unordered_map<char,vector<string>>input;
        words=input;
    }
    
    void insert(string word) {
        words[word[0]].push_back(word); // pushing back starting letter of the word and entire word
        wordcount[word]++; // count 
    }
    
    bool search(string word) {
        if(wordcount[word]>0){ // checks if the string is present
            return true;
        }
        return false;
    }

       bool startsWith(string prefix) {
        for (auto str : words[prefix[0]]) { // iterates over the string which starts with first letter of the prefix
            if (str.find(prefix) == 0) { // checks if the words has the prefix.
                return true;
            }
        }
        return false;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */