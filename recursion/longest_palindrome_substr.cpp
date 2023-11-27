#include <bits/stdc++.h>
#include "palindrome.cpp"
using namespace std;

string longest_palindrome_substr(string s)
{
    if (is_palindrome(s))
        return s;
    string aux1 = longest_palindrome_substr(s.substr(1));
    string aux2 = longest_palindrome_substr(s.substr(0, s.size() - 1));
    return aux1.size() > aux2.size() ? aux1 : aux2;
}

int main()
{
    string s;
    cin >> s;
    cout << longest_palindrome_substr(s) << endl;
    return 0;
}