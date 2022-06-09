class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
           int a=0,b=0;
           for( int i = 0 ; i < numbers.size()-1 ; i++ )
           {
                int l = i + 1 ;
                int h = numbers.size() -1 ;
                while( l <= h )
                {
                    int mid = (l+h)/2 ;
                    if(numbers[mid] == ( target - numbers[i]))
                    {
                        a = i+1 ;
                        b = mid +1 ;
                        break ;
                    }
                    else if(numbers[mid] < ( target - numbers[i] ))
                    {
                        l = mid+1;
                    }
                    else
                        h = mid - 1 ;
                }
            }
            return {a,b } ;
    }
};