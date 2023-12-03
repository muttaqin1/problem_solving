#include <bits/stdc++.h>
using namespace std;

int count_elements(vector<int> arr, int i)
{
    if (i >= arr.size())
        return 0;
    int aux = count_elements(arr, i + 1);
    if (*find(arr.begin(), arr.end(), arr[i] + 1) == arr[i] + 1)
        return ++aux;
    else
        return aux;
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
    cout << count_elements(arr, 0) << endl;

    return 0;
}