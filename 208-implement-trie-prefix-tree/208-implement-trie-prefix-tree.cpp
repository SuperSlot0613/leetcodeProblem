struct Node{
    Node* links[26];
    bool flag=false;
    bool containKeys(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void putLinks(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
};


class Trie {
    
    private: Node* root;
    
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        
        Node* node=root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                node->putLinks(word[i],new Node());
            }
            node=node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                return false;
            }
            node=node->getNode(word[i]);
        }
        
        return (node->flag==true);
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containKeys(prefix[i])){
                return false;
            }
            node=node->getNode(prefix[i]);
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