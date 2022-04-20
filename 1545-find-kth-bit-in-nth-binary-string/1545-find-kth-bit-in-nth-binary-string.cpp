class Solution {
public:
     string invert(string s)
    {
        string answer;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1')
            {
                answer += '0';
            }
            else
            {
                answer += '1';
            }
        }
        return answer;
    }
    string former(int n)
    {
        if(n == 1)
        {
            return "0";
        }
        string smallanswer = former(n-1);
        string helper = invert(smallanswer);
        reverse(helper.begin(), helper.end());
        return smallanswer + "1" + helper;
    }
    char findKthBit(int n, int k) 
    {
        string s = '0' + former(n);
        //cout<<s<<endl;
        int start = 1;
        int end = s.length();
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(mid == k)
            {
                return s[mid];
            }
            else if(mid > k)
            {
                end = mid - 1;
            }
            else 
            {
                start= mid + 1;
            }
        }
        return s[0];
        
    }
};