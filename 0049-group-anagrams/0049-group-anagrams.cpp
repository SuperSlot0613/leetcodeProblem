class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> vis;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            string str1=str;
            sort(str.begin(),str.end());
            if(vis.find(str)==vis.end()){
                vis[str]={str1};
            }else{
                vis[str].push_back(str1);
            }
        }
        map<string,vector<string>>:: iterator itr;
        vector<vector<string>> ans;
        for (itr = vis.begin(); itr != vis.end(); itr++)
        {
            ans.push_back(itr->second);
        }
        return ans;
    }
};