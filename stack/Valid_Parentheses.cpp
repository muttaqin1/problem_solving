#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto v : s)
        {
            if (v == '(' || v == '[' || v == '{')
            {
                st.push(v);
            }
            else
            {
                if (st.empty())
                    return false;
                if (v == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (v == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (v == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        return st.empty();
    }
};
