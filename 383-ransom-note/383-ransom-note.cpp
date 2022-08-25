class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            if(mp.find(magazine[i])!=mp.end()){
                if(mp[magazine[i]]!=0){
                     mp[magazine[i]]--;
                }
            }
        }
        
        for(int i=0;i<ransomNote.size();i++){
            if(mp[ransomNote[i]]!=0){
                return false;
            }
        }
        return true;
    }
};