#include <bits/stdc++.h>
using namespace std;

void target_sum(int i, int sum, int req_sum, vector<int> arr, vector<int> subset, vector<vector<int>> &result)
{
    if (sum == req_sum)
    {
        result.push_back(subset);
        return;
    }
    else if (i >= arr.size() || sum > req_sum)
        return;

    subset.push_back(arr[i]);
    target_sum(i + 1, sum += arr[i], req_sum, arr, subset, result);
    subset.pop_back();
    target_sum(i + 1, sum -= arr[i], req_sum, arr, subset, result);
};