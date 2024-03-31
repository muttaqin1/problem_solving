#include <bits/stdc++.h>
using namespace std;
bool helper(char a, char b, string str, int i)
{
    if (str[i] == a && str[i + 1] == b)
        return true;
    if (str[i] == b && str[i + 1] == a)
        return true;
    return false;
}

string solve(int i, string str, string res, int n)
{
    if (i == n)
        return res;
    if (i + 1 == n)
    {
        if (res.back() == str[i])
        {
            res.pop_back();
            return res;
        }
        return res + str[i];
    }
    if (helper('R', 'B', str, i))
    {
        if (res.back() == 'P')
        {
            res.pop_back();
            return solve(i + 2, str, res, n);
        }
        return solve(i + 2, str, res + 'P', n);
    }
    else if (helper('R', 'G', str, i))
    {
        if (res.back() == 'Y')
        {
            res.pop_back();
            return solve(i + 2, str, res, n);
        }
        return solve(i + 2, str, res + 'Y', n);
    }
    else if (helper('B', 'G', str, i))
    {
        if (res.back() == 'C')
        {
            res.pop_back();
            return solve(i + 2, str, res, n);
        }
        return solve(i + 2, str, res + 'C', n);
    }
    else
        return solve(i + 2, str, res, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        string res = solve(0, str, "", n);
        cout << res << endl;
    }
    return 0;
}