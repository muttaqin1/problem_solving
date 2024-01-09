#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int parse_int(string str)
    {
        int val = 0;

        for (auto v : str)
        {
            val *= 10;
            val += (v - '1') + 1;
        }
        return val;
    }
    bool is_valid(string temp)
    {
        if (temp[0] == '0')
            return false;
        if (temp.size() > 3)
            return false;
        int val = this->parse_int(temp);
        if (val < 0 || val > 255)
            return false;

        return true;
    }
    void helper(int i, int stop, int max_stop, string s, string temp, vector<string> &res)
    {
        if (i >= s.size())
        {
            if (stop != max_stop)
                return;
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        if (i < s.size() && stop >= max_stop)
            return;
        string current_char = string(1, s[i]);
        helper(i + 1, stop + 1, max_stop, s, temp + current_char + ".", res);
        for (int j = i + 1; j < s.size(); j++)
        {
            current_char += s[j];
            if (is_valid(current_char))
            {
                helper(j + 1, stop + 1, max_stop, s, temp + current_char + ".", res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        this->helper(0, 0, 4, s, {}, res);
        return res;
    }
};
