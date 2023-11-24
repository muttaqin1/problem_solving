#include <string>

bool is_palindrome(std::string s)
{
    if (s.size() <= 1)
        return true;
    else if (s[0] != s[s.size() - 1])
        return false;
    else
        return is_palindrome(s.substr(1, s.size() - 2));
}