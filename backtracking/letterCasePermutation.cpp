#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        this->helper(0, s, "", res);
        return res;
    }
    void helper(int i, string s, string ans, vector<string> &res)
    {
        if (i >= s.size())
        {
            res.push_back(ans);
            return;
        }
        if (s[i] >= '0' && s[i] <= '9')
            return helper(i + 1, s, ans + s[i], res);
        else
        {

            helper(i + 1, s, ans + s[i], res);
            helper(i + 1, s, ans + char(toupper(s[i])), res);
        }
    }
};

int main()
{
    Solution s;
    vector<string> v = s.letterCasePermutation("0");
    for (auto a : v)
        cout << a << " ";
    cout << endl;
    return 0;
}