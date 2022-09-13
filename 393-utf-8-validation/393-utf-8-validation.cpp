class Solution {
public:
   bool validUtf8(vector<int> &data){
  
    int num = data.size(); 
    int check = 0;   
    for (int i = 0; i < num; i++){    
      int temp = data[i]; 
      if (check==0){ 
        if ((temp/32) == 0b110) 
          check = 1;  
        else if ((temp/16) == 0b1110)
          check = 2; 
        else if ((temp /8) == 0b11110)
          check = 3; 
        else if ((temp /128))
          return false; 
      }else{
        if ((temp /64) != 0b10)
          return false; 
        check--;        
      }
    }
    return (check == 0); 
  }
};