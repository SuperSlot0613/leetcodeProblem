class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> mp;
        for(int i=0,j=97;i<key.size();i++){
            if(mp.find(key[i])!=mp.end() || key[i]==' '){
                continue;
            }
            mp[key[i]]=char(j);
            j++;
        }
        // for(auto it:mp){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }
        string ans="";
        for(int i=0;i<message.size();i++){
            if(message[i]==' '){
                ans=ans+" ";
                continue;
            }
            ans=ans+mp[message[i]];
        }
        return ans;
    }
};