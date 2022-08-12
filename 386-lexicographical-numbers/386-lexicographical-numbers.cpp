class Solution {
public:
    
    void lexicor(int n,int i,vector<int>&dp){
        if(i>n) return;
        if(i!=0){
            dp.push_back(i);
        }
        for(int j=(i==0)?1:0;j<=9;j++){
            lexicor(n,10*i+j,dp);
        }
    }
    
    
    vector<int> lexicalOrder(int n) {
        vector<int> dp;
        lexicor(n,0,dp);
        return dp;
    }
};