#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    char symbol_begin = '\\';
    char symbol_end = '/';
    int inner_space = n - 2;
    int outer_space = 0;
    int mid = ceil((n * 1.0) / 2);

    if (n == 1)
    {
        cout << "X" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < outer_space; j++)
            cout << " ";

        if (i != mid)
        {
            cout << symbol_begin;
            for (int k = 1; k <= inner_space; k++)
                cout << " ";
            cout << symbol_end;
        }
        else
        {
            cout << "X";
            swap(symbol_begin, symbol_end);
        }
        if (i >= mid)
        {
            outer_space--;
            inner_space += 2;
        }
        else
        {
            outer_space++;
            inner_space -= 2;
        }
        cout << endl;
    }

    return 0;
}