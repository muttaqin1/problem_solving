#include <bits/stdc++.h>
using namespace std;

bool is_sorted(vector<int> arr, int i)
{
    if (i >= arr.size() - 1)
        return true;
    else if (arr[i] > arr[i + 1])
        return false;
    else
        return is_sorted(arr, i + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = is_sorted(arr, 0);
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}