class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1, st2;
        for (auto v : s)
        {
            if (v != '#')
                st1.push(v);
            else
            {
                if (!st1.empty())
                    st1.pop();
            }
        }
        for (auto v : t)
        {
            if (v != '#')
                st2.push(v);
            else
            {
                if (!st2.empty())
                    st2.pop();
            }
        }
        return st1 == st2;
    }
};