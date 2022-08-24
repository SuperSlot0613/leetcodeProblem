class Solution {
public:
    bool powerTo(int index,int n){
        if(n==pow(3,index)){
            return true;
        }
        
        if(pow(3,index)>n){
            return false;
        }
        
        return powerTo(index+1,n);
        
    }
    
    
    bool isPowerOfThree(int n) {
        return powerTo(0,n);
    }
};