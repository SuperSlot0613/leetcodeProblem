class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size()==0){
        //     return 0;
        // }
        map<char,int> mp;
        int maxi=0;
        int j=0,i=0;
        while(j<s.size()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
                j++;
                int sizee=mp.size();
                maxi=max(sizee,maxi);
            }else{
                mp.erase(s[i]);
                i++;
            }
        }
       
        return maxi;
    }
};