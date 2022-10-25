class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str="",str1="";
        for(int i=0;i<word1.size();i++){
            str+=word1[i];
        }
        for(int i=0;i<word2.size();i++){
            str1+=word2[i];
        }
        if(str==str1){
            return true;
        }
        return false;
    }
};