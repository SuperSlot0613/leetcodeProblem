class Solution {
public:
    int minCost(string c, vector<int>& neededTime) {
      int i=1,j=neededTime[0],ans=0,z=neededTime[0],f=0;
      for(i=1;i<c.length();i++){
           if(c[i-1]==c[i]){
               f=1;
               j+=neededTime[i];
               z=max(z,neededTime[i]);
           } 
            else{
              if(f==1)  ans=ans+j-z;
                j=neededTime[i];
                z=neededTime[i];
                f=0;
                
            }
           
           
        }
         if(f==1)  ans=ans+j-z;
        return ans;
    }
};