class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int larans=0;
        int n=heights.size();
        vector<int> leftsmaller(n,0),rightsmaller(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) leftsmaller[i]=0;
            else leftsmaller[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) rightsmaller[i]=n-1;
            else rightsmaller[i]=st.top()-1;
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            larans=max(larans,heights[i]*(rightsmaller[i]-leftsmaller[i]+1));
        }
        
        return larans;
        
        
    }
};