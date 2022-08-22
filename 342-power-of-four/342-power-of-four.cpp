class Solution {
public:
    bool powerTo(int index,int n){
        if(n==pow(4,index)){
            return true;
        }
        
        if(pow(4,index)>n){
            return false;
        }
        
        return powerTo(index+1,n);
        
    }
    
    
    bool isPowerOfFour(int n) {
        return powerTo(0,n);
    }
};