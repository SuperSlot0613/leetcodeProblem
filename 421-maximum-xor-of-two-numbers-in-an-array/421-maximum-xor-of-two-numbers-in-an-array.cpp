struct Node{
    Node* links[2];
    
    bool containkeys(int bit){
        return (links[bit]!=NULL);
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit,Node* node){
        links[bit]=node;
    }
    
};

class Trie{
    private:Node* root;
    public:
    Trie(){
        root=new Node();
    }
    public:
    void Insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!node->containkeys(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    public:
    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->containkeys(1-bit)){
                maxNum=maxNum | (1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        
        for(int i=0;i<nums.size();i++){
            trie.Insert(nums[i]);
        }
        int maxi=0;
        for(auto &it:nums){
            maxi=max(maxi,trie.getMax(it));
        }
        
        return maxi;
    }
};