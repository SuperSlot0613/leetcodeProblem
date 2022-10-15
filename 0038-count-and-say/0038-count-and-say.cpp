class Solution {
public:
    
    string test(string str){
        int i=1, count=1;
        char prev=str[0];
        string ans="";
        while(i<str.size()){
            if(str[i]==prev){
                count++;
            }else{
                // cout<<count<<" "<<prev<<endl;
                ans=ans+to_string(count)+prev;
                prev=str[i];
                count=1;
            }
            i++;
        }
        ans+=to_string(count)+prev;
        return ans;
    }
    
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string str="1";
        for(int i=1;i<n;i++){
            string temp=test(str);
            // cout<<temp<<endl;
            str=temp;
            // cout<<str<<endl;
        }
        return str;
    }
};