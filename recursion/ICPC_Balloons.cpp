#include <bits/stdc++.h>
using namespace std;

int count_balloons(string s, int i)
{
    if (i >= s.size())
        return 0;
    int aux = count_balloons(s, i + 1);
    if (s.find(s[i], i + 1) <= s.size())
        return aux + 1;
    else
        return aux + 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        getchar();
        string str;
        cin >> str;
        cout << count_balloons(str, 0) << endl;
    }

    return 0;
}