struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containkeys(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:Node* root;
    public:
    Trie(){
        root=new Node();
    }
    public:
    void Insert(string words){
        Node* node=root;
        for(int i=0;i<words.size();i++){
            if(!node->containkeys(words[i])){
                node->put(words[i],new Node());
            }
            node=node->get(words[i]);
        }
        node->setEnd();
    }
    
    public:
    bool checkIfPrefixExists(string word){
        bool fl=true;
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containkeys(word[i])){
                node=node->get(word[i]);
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
     bool isSubsequence(string x, string y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x[j] == y[i])
                j++;
        return j == x.length();
    }
    
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string longest="";
        for(auto &it:dictionary){
            if(isSubsequence(it,s)){
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