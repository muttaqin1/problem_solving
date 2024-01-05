#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search_word(int i, int row, int col, vector<vector<char>> &board, string word, vector<vector<bool>> &visited)
    {
        if (i >= word.size())
            return true;
        if (row < 0 || col < 0 || row == board.size() || col == board[0].size() || visited[row][col])
            return false;
        if (word[i] != board[row][col])
            return false;
        visited[row][col] = true;
        bool aux1 = search_word(i + 1, row - 1, col, board, word, visited);
        bool aux2 = search_word(i + 1, row, col - 1, board, word, visited);
        bool aux3 = search_word(i + 1, row + 1, col, board, word, visited);
        bool aux4 = search_word(i + 1, row, col + 1, board, word, visited);
        visited[row][col] = false;
        return aux1 || aux2 || aux3 || aux4;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bool flag = false;
        for (int i = 0; i < board.size(); i++)
        {

            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    flag = search_word(0, i, j, board, word, visited);
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        return flag;
    }
};
