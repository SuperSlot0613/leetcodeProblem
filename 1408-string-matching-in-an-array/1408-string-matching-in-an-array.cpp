class Solution {
public:
    
    bool static compare(string a,string b)
    {
        return a.length()<b.length();
    }
    
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        vector<string> myvec;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[j].find(words[i]) != -1){
                    myvec.push_back(words[i]);
                    break;
                }
            }
        }
        
        return myvec; 
    }
};