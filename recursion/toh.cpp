#include <bits/stdc++.h>
using namespace std;

void towers_of_Hanoi(int n, char o, char d, char a)
{
    if (n == 1)
        cout << "Move disk " << n << " from rod " << o << " to rod " << d << endl;
    towers_of_Hanoi(n - 1, o, a, d);
    cout << "Move disk " << n << " from rod " << o << " to rod " << d << endl;
    towers_of_Hanoi(n - 1, a, d, o);
}
int main()
{
    char o = 'O';
    char d = 'D';
    char a = 'A';
    towers_of_Hanoi(4, o, d, a);
    return 0;
}