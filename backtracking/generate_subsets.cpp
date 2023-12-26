#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subset(vector<int> arr, int i)
{
    if (i >= arr.size())
        return {{}};
    vector<vector<int>> aux = subset(arr, i + 1);
    vector<vector<int>> ans;
    for (auto v : aux)
        ans.push_back(v);
    for (auto v : aux)
    {
        vector<int> temp;
        temp.push_back(arr[i]);
        for (auto u : v)
        {
            temp.push_back(u);
        }
        ans.push_back(temp);
    }
    return ans;
}

void subset_alt(vector<int> arr, int i, vector<int> subset, vector<vector<int>> &result)
{
    if (i >= arr.size())
    {
        result.push_back(subset);
        return;
    }
    subset.push_back(arr[i]);
    subset_alt(arr, i + 1, subset, result);
    subset.pop_back();
    subset_alt(arr, i + 1, subset, result);
}

int main()
{

    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> subset;
    subset_alt(arr, 0, subset, result);
    for (auto v : result)
    {
        if (v.empty())
        {
            cout << "[]" << endl;
            continue;
        }
        for (auto u : v)
        {
            cout << u;
        }
        cout << endl;
    }
    return 0;
}