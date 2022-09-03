class Solution {
public:
    
   void dfstravel(int n,int num,int k,vector<int> &ans){
       if(n==0){
           ans.push_back(num);
           return;
       }
       vector<int> temp;
       int last=num%10;
       temp.push_back(last+k);
       if(k!=0){
           temp.push_back(last-k);
       }
       for(auto it:temp){
           if(it>=0 && it<10){
               int val=num*10+it;
               dfstravel(n-1,val,k,ans);
           }
       }
   }
    
    vector<int> numsSameConsecDiff(int n, int k) {
       if(n==1){
           return {0,1,2,3,4,5,6,7,8,9};
       }
       vector<int> ans;
       for(int i=1;i<10;i++){
            dfstravel(n-1,i,k,ans);
       }
       return ans;
    }
};