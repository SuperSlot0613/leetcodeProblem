class Solution {
public:
     bool isSubsequence(string s,string x){
        int j=0;
        for(int i=0;i<s.size() && j<x.size();i++){
            if(s[i]==x[j]){
                j++;
            }
        }
        
        return j==x.size();
    }
      
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        unordered_map<string,int> mp;
        for(auto &it:words){
            mp[it]++;
        }
        for(auto &it: mp){
            if(isSubsequence(s,it.first)){
                count+=it.second;
            }
        }
        
        return count;
        
        
    }
};