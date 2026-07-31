#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };
    
    TrieNode* root;
    
    bool dfsSearch(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        
        char c = word[index];
        if (c == '.') {
            // Try all possible children
            for (auto& [ch, child] : node->children) {
                if (dfsSearch(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.count(c) == 0) return false;
            return dfsSearch(word, index + 1, node->children[c]);
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.count(c) == 0) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }
};

