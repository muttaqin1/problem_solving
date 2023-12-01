#include <bits/stdc++.h>
using namespace std;

vector<long long int> prefix_sum(vector<long long int> arr, int i)
{
    if (i == 0)
        return {arr[i]};
    vector<long long int> aux = prefix_sum(arr, i - 1);
    aux.push_back(arr[i] + aux.back());
    return aux;
}

int main()
{
    long long int n, q;
    cin >> n >> q;
    vector<long long int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<long long int> prefix_sum_arr = prefix_sum(arr, arr.size() - 1);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0)
            cout << prefix_sum_arr[r] << endl;
        else
            cout << prefix_sum_arr[r] - prefix_sum_arr[l - 1] << endl;
    }

    return 0;
}