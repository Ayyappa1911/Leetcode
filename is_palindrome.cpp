class Solution 
{
    public:
    
        bool isPalindrome(int x) 
        {
            vector<int> v;
            if(x<0)
            {
                return false;
            }
            while(x)
            {
                int a = x%10;
                v.push_back(a);
                x = x/10;
            }
            int i = 0;
            for(auto it : v)
            {
                i++;
            }
            int flag = 0;
            for(int j = 0;j<i/2;j++)
            {
                if(v[j] != v[i-1-j] )
                {
                    flag = 1;
                }
            }
            if(flag == 1)
            {
                return false;
            }
            return true;
        }
};
