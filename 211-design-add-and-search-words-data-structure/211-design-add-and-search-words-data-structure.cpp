class WordDictionary {
public:
    WordDictionary* children[26];
    bool word_end = false;
    WordDictionary() {
      for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
    
    void addWord(const string& word) {
      int ch;
      WordDictionary* node = this;
      for(int i = 0; i < word.size(); i++) {
        ch = word[i] - 'a';
        if(!node->children[ch]) node->children[ch] = new WordDictionary();
        node = node->children[ch];
      }
      node->word_end = true;
    }
    
    bool search(const string& word, int start = 0) {
      if(start==word.size() && this->word_end) return true; 
      else if (start==word.size()) return false;
      if (word[start]=='.') {
        for(int i = 0; i < 26; i++) {
          if(this->children[i] && this->children[i]->search(word, start+1)) return true;
        }
        return false;
      }
      else {
        int ch = word[start] - 'a';
        if(!(this->children[ch])) return false;
        else return this->children[ch]->search(word, start+1);
      }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */