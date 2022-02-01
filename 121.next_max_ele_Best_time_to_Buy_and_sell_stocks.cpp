

// We should be able to find next largest element for each of the element in the given list

//we should find the maximum profit by find the maximum of difference between next highest value - presnt value for each element


#include<iostream>
#include<vector>
using namespace std;


int maxProfit(vector<int>& Arr)
{
    int nmp[Arr.size()];//next maximum prices
    int max1 = 0;
    for(int i = Arr.size()-1;i>=0;i--)
    {
        if(i == Arr.size() -1)
        {
            nmp[i] = Arr[i];
            cout << nmp[i] << endl ;
        }
        else
        {
            nmp[i] = max(Arr[i],nmp[i+1]);
            cout << nmp[i] << endl ;
        }
        max1 = max(max1,(nmp[i]-Arr[i]));
    }
    return max1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> Arr;
    for(int i = 0;i<n;i++)
    {
        int a;
        cin >> a;
        Arr.push_back(a); 
    }  
    cout << maxProfit(Arr) << endl;  
    return 0;
}
