class Solution {
public:
    bool isbooll(vector<int> arr){
        if(arr[0]==0) return false;
        
        int num=0;
        for(int val:arr){
            num=10*num+val;
        }
        
        while(num>0 && ((num&1)==0)){
            num>>=1;
        }
        
        return num==1;
        
    }
    
    
    bool permutation(vector<int> arr,int start){
        if(start==arr.size()){
            return isbooll(arr);
        }
        
        for(int i=start;i<arr.size();i++){
            swap(arr[i],arr[start]);
            if(permutation(arr,start+1)){
                return true;
            }
            swap(arr[i],arr[start]);
        }
        return false;
    }
    
    vector<int> count(int N) {
        vector<int> ans(10);
        while (N > 0) {
            ans[N % 10]++;
            N /= 10;
        }
        return ans;
    }
    
    
    bool reorderedPowerOf2(int n) {
        vector<int> ans=count(n);
        for(int i=0;i<31;i++){
            if(ans==count(1<<i)){
                return true;
            }
        }
        return false;
        
    }
};