
class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        string ans="";
        map<string, int> mp;
        int j=0;
        for(int i=0;i<d.size();i++)
        {
            mp[d[i]]++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            bool pushed=false;
            while(i<s.size() && s[i] !=' ' )
            {
                
                string x=s.substr(j,i-j+1);
                
                if(mp.count(x) && pushed == false) {
                    ans += x ;
                    pushed= true;
                    
                }
                i++;
            }
            if(i<s.size()-1 && pushed) ans +=" ";
            if(pushed==false) ans += s.substr(j,i-j+1);
                j=i+1;
        }
        return ans;
    }
};