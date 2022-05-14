
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offlinequeries;
        int q=queries.size();
        for(int i=0;i<q;i++){
            offlinequeries.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offlinequeries.begin(),offlinequeries.end());
        vector<int> ans(q,0);
        int n=nums.size();
        int ind=0;
        Trie trie;
        for(int i=0;i<q;i++){
            int ai=offlinequeries[i].first;
            int xi=offlinequeries[i].second.first;
            int qindex=offlinequeries[i].second.second;
            while(ind<n && nums[ind]<=ai){
                trie.Insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qindex]=-1;
            else ans[qindex]=trie.getMax(xi);
        }
        return ans;
    }
};