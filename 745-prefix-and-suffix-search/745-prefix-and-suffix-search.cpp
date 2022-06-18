class WordFilter {
    struct TrieNode {
        array<unique_ptr<TrieNode>, 27> children;
        int max_id;
    };
    TrieNode trie;
	
    void insert(string const& key, int id) {
        auto node = &trie;
        for (int i = 0; i < key.size(); ++i) {
            int c = key[i] - 'a';
            if (node->children[c]) {
                node = node->children[c].get();
            } else {
                node->children[c].reset(node = new TrieNode());
            }
            node->max_id = id;
        }
    }
	
    int query(string const& key) const {
        auto node = &trie;
        for (int i = 0; i < key.size(); ++i) {
            int c = key[i] - 'a';
            if (node->children[c]) {
                node = node->children[c].get();
            } else {
                return -1;
            }
        }
        return node->max_id;
    }
public:
    WordFilter(vector<string>& words) {
        for (int k = 0; k < words.size(); ++k) {
            string const& word = words[k];
            int const n = word.size();
            for (int i = 1; i <= n; ++i) {
                string key = word.substr(n-i, i);
                key += '{';
                key.append(word);
                insert(key, k);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        suffix += '{';
        suffix += prefix;
        return query(suffix);
    }
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */