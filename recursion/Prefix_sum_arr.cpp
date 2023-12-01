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

    return 0;
}