class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            int l=0,mid,e=arr2.size()-1;
            while(l<=e){
                mid=l+(e-l)/2;
                if(abs(arr1[i]-arr2[mid])<=d){
                    count--;
                    break;
                }
                if(arr1[i]>arr2[mid]){
                    l=mid+1;
                }else{
                    e=mid-1;
                }
            }
            count++;
            
        }
        return count;
    }
};