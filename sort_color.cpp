class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        unordered_map<int,int> umap;
        umap[0] = 0;
        umap[1] = 0;
        umap[2] = 0;
        for(auto it : nums)
        {
            umap[it] += 1;
            cout << it << " ";
        }
        cout<< endl << umap[0] << umap[1] << umap[2]; 
        int a = nums.size();
        for(int i = 0;i<a;i++)
        {
            nums.pop_back();
        }
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<umap[i];j++)
            {
                nums.push_back(i);
            }
        }
    }
};
