class Solution {
public:
    
    bool powerTo(int index,int n){
        if(n==pow(2,index)){
            return true;
        }
        
        if(pow(2,index)>n){
            return false;
        }
        
        return powerTo(index+1,n);
        
    }
    
    
    bool isPowerOfTwo(int n) {
        return powerTo(0,n);
    }
};