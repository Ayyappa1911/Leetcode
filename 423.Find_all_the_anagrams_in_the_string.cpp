class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int a = 0;
        int a1 = 0;
        long int a2 = 0;
        for(auto it : p)
        {
            a = a + it;
            a1 = a1 + it*it;
            a2 = a2 + it*it*it;
        }
        vector<int> r;
        int index = 0;
        int temp = 0;
        int temp1 = 0;
        long int temp2 = 0;
        for(int i = 0;i<p.size();i++)
        {
            temp += s[i];
            temp1 += s[i]*s[i];
            temp2 += s[i]*s[i]*s[i];
        }
        if(temp == a && temp1 == a1 && temp2 == a2)
        {
            r.push_back(index);
        }
        index++;
        int x = 0;
        for(int i = p.size();i<s.size();i++)
        {
            temp =temp -s[x];
            temp1 = temp1 - s[x]*s[x];
            temp2 = temp2 - s[x]*s[x]*s[x];
            temp = temp + s[i];
            temp1 = temp1 + s[i]*s[i];
            temp2 = temp2 + s[i]*s[i]*s[i];
            
            if(temp == a && temp1 == a1 && temp2 == a2)
            {
                 r.push_back(index);
            }
            index++;
            x++;
        }
        return r;
    }

};
