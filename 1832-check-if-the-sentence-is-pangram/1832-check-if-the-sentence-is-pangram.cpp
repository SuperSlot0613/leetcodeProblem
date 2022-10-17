class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        for(int i=0;i<sentence.length();i++){
            char ch=sentence[i];
            int index=ch-'a';
            v[index]+=1;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]<1){
                return false;
            }
        }
        return true;
    }
};