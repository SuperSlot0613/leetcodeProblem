
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        unordered_map<string,int> mp;
        for(int i = 0; i<s.size();++i){
            string re;
            vector<int> nums = {0}; int l = 0;
            for(int j = i+1; j<s.size();++j){
                re+=string(1,s[j]);
                while(l>0 && s[i+l]!=s[j])  l = nums[l-1];
                if(s[l+i]==s[j]) {nums.push_back(l+1); l++;}
                else nums.push_back(0);
                int p = j-i+1 - nums[nums.size()-1];
                if((j-i)%2!=0 && (p && (j-i+1)%p==0 && ((j-i+1)/p)%2==0)) mp[re]++; 
            }
        }
        return mp.size();
    }
};