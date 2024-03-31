#include <bits/stdc++.h>
using namespace std;

void generate_parenthesis(string res, int op, int cl, int n)
{
    if (op == n && cl == n)
    {
        cout << res << endl;
        return;
    }
    if (op < n)
        generate_parenthesis(res + '(', op + 1, cl, n);
    if (cl < op)
        generate_parenthesis(res + ')', op, cl + 1, n);
}

int main()
{
    int n = 2;
    generate_parenthesis("", 0, 0, n);
    return 0;
}