class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector <int> v;
        unordered_map<int,int> umap;
        for(auto it : nums)
        {
            umap[it] += 1;
        }
        for(auto x: umap)
        {
            if(x.second >1)
            {
                v.push_back(x.first);
            }
        }
        return v;
    }
};
