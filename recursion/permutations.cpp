#include <bits/stdc++.h>
using namespace std;

void permute(string &s, int pos, vector<string> &res)
{
    if (pos >= s.size())
    {
        res.push_back(s);
        return;
    }
    for (int i = pos; i < s.size(); i++)
    {
        swap(s[i], s[pos]);
        permute(s, pos + 1, res);
        swap(s[i], s[pos]);
    }
}

int main()
{
    vector<string> result;
    string s = "ABC";
    permute(s, 0, result);
    for (auto v : result)
    {
        cout << v << endl;
    }

    return 0;
}