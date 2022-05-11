class Solution {
public:
    int countans=0;
     void dfs(int i,int count, vector<char>& path,int k,vector<char> val) {
        if(count == 0 && path.size()==k) {
            countans++;
            return;
        }
        
         if(count==0 || path.size()==k){
             return;
         }
         
        if(count > 0 && i < val.size()) {
            path.push_back(val[i]);
            dfs(i++,count-1, path,k,val);
            path.pop_back();
        }
        
        //leave it
        dfs(i++,count, path,k,val);
    }
    
    int countVowelStrings(int n) {
         int a=1, e=1, i=1, o=1, u=1;
        
        while(--n){
            o += u;
            i += o;
            e += i;
            a += e;
        }
        
        return a+e+i+o+u;
    }
};