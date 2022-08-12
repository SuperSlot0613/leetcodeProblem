struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containkey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* getnode(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
    
};

class Trie{
  private: Node* root;
  public:
    Trie(){
        root=new Node();
    }
    
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getnode(word[i]);
        }
        node->setEnd();
    }
    
    bool checkPrefix(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containkey(word[i])){
                node=node->getnode(word[i]);
                if(node->isEnd()==false){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto &it:words){
            trie.insert(it);
        }
        
        string longest="";
        for(auto &it:words){
            if(trie.checkPrefix(it)){
                if(it.size()>longest.size()){
                    longest=it;
                }else if(it.size()==longest.size() && it<longest){
                    longest=it;
                }
            }
        }
        if(longest=="") return "";
        return longest;
    }
};