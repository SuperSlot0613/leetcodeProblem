class Solution {
public:
     bool powerTo(int index,int n,long sum,int inc){
        sum=sum+pow(3,index);
        if(n==sum){
            return true;
        }
        
        if(sum>n){
            return false;
        }
        
        return powerTo(index+inc,n,sum,inc);
        
    }
    
    
    bool checkPowersOfThree(int n) {
        
        int r;
        while(n>0){
           r=n%3;
           if(r>1){
             return false;
           }
           n=n/3;
        }
        return true;
    }
};