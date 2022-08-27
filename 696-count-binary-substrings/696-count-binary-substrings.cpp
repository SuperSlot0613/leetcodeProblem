class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int count=1,ans=0,prev=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                ans+=min(prev,count);
                prev=count;
                count=1;
            }else{
                count++;
            }
        }
        
        return ans+min(prev,count);
    }
};