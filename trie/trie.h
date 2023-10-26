#include <unordered_map>
#include <string>

namespace N {
    struct TrieNode {
        bool end_of_word = false;
        std::unordered_map<char, TrieNode*> children;
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }
        
        void insert(std::string word) {
            TrieNode* node = root;
            for (char c: word) {
                if (!node->children.count(c)) {
                    node->children.insert({c, new TrieNode()});
                }
                node = node->children[c];
            }
            node->end_of_word = true;
        }

        TrieNode* find(std::string prefix) {
            TrieNode* node = root;
            for (char c: prefix) {
                if (node->children.count(c)) {
                    node = node->children[c];
                } else {
                    return nullptr;
                }
            }
            return node;
        }
        
        bool search(std::string word) {
            TrieNode* node = find(word);
            if (!node) return false;
            return node->end_of_word;
        }
        
        bool startsWith(std::string prefix) {
            TrieNode* node = find(prefix);
            if (!node) return false;
            return true;
        }
    };
}