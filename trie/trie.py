class TrieNode:
    def __init__(self):
        self.end_of_word = False
        self.children = dict()

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.end_of_word = True

    def find(self, prefix: str) -> TrieNode:
        node = self.root
        for c in prefix:
            node = node.children.get(c)
            if node is None:
                return None
        return node

    def search(self, word: str) -> bool:
        node = self.find(word)
        if node is None:
            return False
        return node.end_of_word

    def startsWith(self, prefix: str) -> bool:
        node = self.find(prefix)
        return node is not None