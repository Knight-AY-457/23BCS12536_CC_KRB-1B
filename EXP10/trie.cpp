#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(node->children[index] == NULL) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(node->children[index] == NULL) return false;
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 1
    cout << trie.search("app") << endl;     // 0
    cout << trie.startsWith("app") << endl; // 1

    trie.insert("app");
    cout << trie.search("app") << endl;     // 1

    return 0;
}
