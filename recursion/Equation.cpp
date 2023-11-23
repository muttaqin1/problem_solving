#include <bits/stdc++.h>
using namespace std;

long long int equation(int x, int n)
{
    if (n <= 0)
        return 0;
    return pow(x, n) + equation(x, n - 2);
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << equation(x, n % 2 ? n - 1 : n);
    return 0;
}