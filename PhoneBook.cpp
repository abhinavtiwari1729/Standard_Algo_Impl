#include<iostream>
#include<string>

using namespace std;

class TrieNode{

public:
    bool isWord;
    TrieNode* list[26];

    TrieNode(){
        for(int i = 0 ; i < 26 ; i++){
            list[i] = nullptr;
        }

        isWord = false;
    }

};



class Trie {
private:

    TrieNode * root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        
        TrieNode *node = root;
        for(int i = 0 ;  i<word.size() ; i++){

            if(node->list[word[i] - 'a'] == nullptr){
               node->list[word[i] - 'a'] = new TrieNode();
               node =  node->list[word[i] - 'a'];        
            }
            else{
                node = node->list[word[i] - 'a'];
            }    
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        
        TrieNode *node = root;
        for(int i = 0 ;  i<word.size() ;  i++) {

            if(node->list[word[i]-'a'] == nullptr)
                return false;
            else
                node = node->list[word[i]-'a'];
        }
        if(node->isWord == true)
            return true;
        return false;
    }
    
    bool startsWith(string word) {
        TrieNode *node = root;
        for(int i = 0 ;  i<word.size() ;  i++) {

            if(node->list[word[i]-'a'] == nullptr)
                return false;
            else
                node = node->list[word[i]-'a'];
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