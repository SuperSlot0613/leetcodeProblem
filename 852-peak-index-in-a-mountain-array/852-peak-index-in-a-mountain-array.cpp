class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,e=n-1;
        while(l<=e){
            int mid=l+(e-l)/2;
            if(arr[mid]<arr[mid+1]){
                l=mid+1;
            }else{
                e=mid-1;
            }
        }
        return l;
    }
};