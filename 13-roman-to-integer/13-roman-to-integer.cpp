class Solution {
public:
    int romanToInt(string s) {
          map<char,int> mp;
          mp['I']=1;mp['V']=5;mp['X']=10;mp['L']=50;mp['C']=100;
          mp['D']=500;
          mp['M']=1000;
          vector<int> v;
          for(int i=0;i<s.length();i++){
              v.push_back(mp[s[i]]);
          }
          long long ans=0; 
          for(int i=0;i<v.size();){
              if(i==v.size()-1){
                  ans=ans+v[i];
                  i++;
              }else if(v[i]<v[i+1]){
                  ans=ans+v[i+1]-v[i];
                  i=i+2;
              }else{
                  ans=ans+v[i];
                  i++;
              }

          }
         return ans;
    }
};