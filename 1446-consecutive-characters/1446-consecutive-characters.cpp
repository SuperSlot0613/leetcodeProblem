class Solution {
public:
    int maxPower(string s) {
        int count=0;
        int maxval=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==s[i+1]){
                count++;
            }else{
                count=0;
            }
            maxval=max(maxval,count+1);
        }
        return maxval;
        
    }
};